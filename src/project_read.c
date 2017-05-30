#include "project.h"

#include "utils/file.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

BOOL project_read_equal(
	char const * const line,
	ssize_t * const equal_idx)
{
	*equal_idx = 0;
	while (TRUE)
	{
		if (line[*equal_idx] == NULL_TERM)
			return FALSE;

		if (line[*equal_idx] == '=')
			return TRUE;

		(*equal_idx)++;
	}
}

BOOL project_read(project * const p, char const * const path)
{
	FILE *f;
	char *line = NULL;
	size_t len;
	ssize_t read;
	ssize_t eq;

	p->debug_plt_path = NULL;

	f = fopen(path, "r");

	if (!f)
	{
		fprintf(stderr, "unable to open %s\n", path);
		return FALSE;
	}


	while ((read = getline(&line, &len, f)) != -1)
	{
		if (read == 0)
			continue;

		if (line[0] == '#')
			continue;
		
		if (!project_read_equal(line, &eq))
			continue;

		line[eq] = NULL_TERM;

		
		if (strcmp("width", line) == 0)
		{
			p->width = atoi(line + eq + 1);
			continue;
		}

		if (strcmp("height", line) == 0)
		{
			p->height = atoi(line + eq + 1);
			continue;
		}

		if (strcmp("iterations", line) == 0)
		{
			p->iterations = atoi(line + eq + 1);
			continue;
		}

		if (strcmp("init_r_min", line) == 0)
		{
			p->init_r_min = atof(line + eq + 1);
			continue;
		}

		if (strcmp("init_r_max", line) == 0)
		{
			p->init_r_max = atof(line + eq + 1);
			continue;
		}

		if (strcmp("init_i_min", line) == 0)
		{
			p->init_i_min = atof(line + eq + 1);
			continue;
		}

		if (strcmp("init_i_max", line) == 0)
		{
			p->init_i_max = atof(line + eq + 1);
			continue;
		}

		if (strcmp("debug_plt_path", line) == 0)
		{
			if (read <= sizeof("debug_plt_path") + 1)
				continue;

			p->debug_plt_path = (char*) malloc(sizeof(char) * (read - eq - 1));
			strncpy(p->debug_plt_path, line + eq + 1, read - eq - 2);
			p->debug_plt_path[read - eq - 2] = NULL_TERM;
			continue;
		}

		if (strcmp("allow_debug_host", line) == 0)
		{
			p->allow_debug_host = line[eq + 1];
			continue;
		}
	}


	fclose(f);
	free(line);
	return TRUE;
}
