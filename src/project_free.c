#include "project.h"

#include <stdlib.h>

void project_free(project * const proj)
{
	if (proj->debug_plt_path != NULL)
	{
		free(proj->debug_plt_path);
	}
	if (proj->iframe_dir_path != NULL)
	{
		free(proj->iframe_dir_path);
	}
}
