#include "project.h"

#include <stdlib.h>

void project_free(project * const proj)
{
	if (proj->def_plt_path == NULL)
		return;

	free(proj->def_plt_path);
}
