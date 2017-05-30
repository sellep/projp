#include "project.h"

#include <stdlib.h>

void project_free(project * const proj)
{
	if (proj->debug_plt_path == NULL)
		return;

	free(proj->debug_plt_path);
}
