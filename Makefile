CC=@gcc
CFLAGS=-Wall -v -march=haswell -fomit-frame-pointer -O3 -pipe

OBJ=watch.o \
	path_dir.o \
	file_path_combine.o \
	file_fsize.o \
	file_fexists.o \
	file_dexists.o \
	file_fnext.o \
	file_fwrite_all.o \
	file_fread_all.o \
	project_free.o \
	project_exists.o \
	project_uptar.o \
	project_read.o \
	project_read_args.o \
	color_rand.o \
	palette_write.o \
	palette_ipol.o \
	palette_init.o \
	palette_free.o \
	palette_read.o \
	dec_zero.o \
	dec_parse.o \
	dec_rand.o \
	dec_print.o \
	dec_fprint.o \
	dec_ucmp.o \
	dec_cmp.o \
	dec_cpy.o \
	dec_iszero.o \
	dec_uadd.o \
	dec_add.o \
	dec_uadd2i.o \
	dec_usub.o \
	dec_sub.o \
	dec_square.o \
	dec_umul.o \
	dec_mul.o \
	dec_imul.o \
	dec_idiv.o \
	kara_combine.o \
	kara_sub.o \
	kara_add.o \
	kara_mul.o \
	kara.o \
	fast_kara_sub.o \
	fast_kara_mul.o \
	fast_kara.o \
	iframe_init.o \
	iframe_free.o \
	iframe_map.o \
	iframe_writenext.o \
	iframe_write_dbg.o \
	bmp_write.o \
	mandelbrot.o \
	mandelbrot_row.o \
	mandelbrot_cc.o \
	g_mandelbrot_simple.o

TST=dec_uadd_commutative.o \
	dec_add_zero.o \
	dec_add_commutative.o \
	dec_sub_zero.o \
	dec_sub_commutative.o \
	dec_mul_zero.o \
	dec_mul_commutative.o \
	dec_square_mul_equal.o \
	dec_uadd2i_equal.o \
	dec_imul_idiv_equal.o \
	kara_mul_equal.o \
	kara_perf.o \
	test.o

%.o : src/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : src/windows/%.c
	$(CC) $(CFLAGS) `pkg-config --cflags gtk+-3.0` -o obj/$@ -c $<

%.o : src/utils/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : src/media/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : src/math/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : src/math/kara/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : src/math/frac/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : test/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : test/math/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

%.o : test/math/kara/%.c
	$(CC) $(CFLAGS) -o obj/$@ -c $<

all: clean $(OBJ)
	ar rvs lib/libproip.a $(addprefix obj/, $(OBJ))
	$(CC) $(CFLAGS) -o bin/main src/main.c -Llib -lproip `pkg-config --libs gtk+-3.0`

test: all $(TST)
	$(CC) $(CFLAGS) -o bin/test $(addprefix obj/, $(TST)) -Llib -lproip

clean:
	@mkdir -p bin obj lib
	@rm -rf bin/*
	@rm -rf obj/*
	@rm -rf lib/*
