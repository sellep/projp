#include <gtk/gtk.h>

enum rect_flags {
	NONE = 0,
	OPEN = 1,
	CLOSED = 2
};

typedef struct
{
	int x0;
	int x1;
	int y0;
	int y1;
	int flg;
} rect;

static rect _r;

static gint cnvs_leave(GtkWidget *w, GdkEvent *e, gpointer data)
{
	_r.flg = NONE;
	return TRUE;
}

static gint cnvs_press(GtkWidget *w, GdkEventButton *e, gpointer data)
{
	rect *r;
	r = (rect*) data;

	_r.x0 = e->x;
	_r.y0 = e->y;
	_r.flg = OPEN;

	return TRUE;
}

static gint cnvs_release(GtkWidget *w, GdkEventButton *e, gpointer data)
{
	if (_r.flg != OPEN)
		return TRUE;

	_r.x1 = e->x;
	_r.y1 = e->y;
	_r.flg = CLOSED;
	return TRUE;
}

static gint cnvs_move(GtkWidget *w, GdkEventMotion *e, gpointer data)
{
	if (_r.flg != OPEN)
		return TRUE;

	_r.x1 = (int)(e->x);
	_r.y1 = (int)(e->y);
	gtk_widget_queue_draw(w);
	return FALSE;
}

static gboolean back_draw(GtkWidget *w, GdkEvent *e, gpointer data)
{
	GdkPixbuf *pixbuf;
	GError *err = NULL;
	cairo_t *cr;

	pixbuf = gdk_pixbuf_new_from_file((char *) data, &error);
	if(!pixbuf)
	{
		g_printerr("%s\n", error->message);
		g_error_free(error);
		return TRUE;
	}

	cr = gdk_cairo_create(gtk_widget_get_window(w));

	gdk_cairo_set_source_pixbuf(cr, pixbuf, 0, 0);

	cairo_paint (cr);
	cairo_destroy(cr);
	return TRUE;
}

static gboolean cnvs_draw(GtkWidget *w, GdkEvent *e, gpointer data)
{
	cairo_t *cr;

	if (_r.flg != OPEN)
		return TRUE;

	cr = gdk_cairo_create(gtk_widget_get_window(w));

	cairo_set_source_rgb(cr, 255, 0, 0);
	cairo_set_line_width(cr, 1);

	cairo_move_to(cr, _r.x0, _r.y0);
	cairo_line_to(cr, _r.x0, _r.y1);
	cairo_line_to(cr, _r.x1, _r.y1);
	cairo_line_to(cr, _r.x1, _r.y0);
	cairo_line_to(cr, _r.x0, _r.y0);

	cairo_stroke(cr);

	cairo_destroy(cr);
	return TRUE;
}

static void activate(GtkApplication *app, gpointer user_data)
{
	GtkWidget *w;
	GtkWidget *da;
	GtkWidget *bg;
	GtkOverlay *ov;

	w = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(w), "projp debug");
	gtk_window_set_default_size(GTK_WINDOW(w), 400, 300);

	da = gtk_drawing_area_new();
	g_signal_connect(da, "draw", G_CALLBACK(cnvs_draw), NULL);
	g_signal_connect(da, "button_press_event", G_CALLBACK(cnvs_press), NULL);
	g_signal_connect(da, "button_release_event", G_CALLBACK(cnvs_release), NULL);
	g_signal_connect(da, "motion_notify_event", G_CALLBACK(cnvs_move), NULL);
	g_signal_connect(da, "leave_notify_event", G_CALLBACK(cnvs_leave), NULL);

	gtk_widget_set_events(da, GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | GDK_POINTER_MOTION_MASK | GDK_LEAVE_NOTIFY_MASK);

	bg = gtk_drawing_area_new();
	g_signal_connect(da, "draw", G_CALLBACK(back_draw), NULL);

	ov = (GtkOverlay*) gtk_overlay_new();
	gtk_overlay_add_overlay(ov, bg);
	gtk_overlay_add_overlay(ov, da);

	gtk_container_add(GTK_CONTAINER(w), ov);

	gtk_widget_show_all(w);
}

int main(int argc, char **argv)
{
	GtkApplication *app;
	int status;

	app = gtk_application_new("projp.gtk", G_APPLICATION_FLAGS_NONE);
	g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
	status = g_application_run(G_APPLICATION(app), argc, argv);
	g_object_unref(app);

	return status;
}