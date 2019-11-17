#include "ft_select.h"

int get_max_line_show(t_data_pack *pack)
{
	int max_line;
	int max_line_show;

	max_line = get_max_data_line(pack);
	/* if whe whole screen contain all data then do not change line */
	if(max_line < pack->vdata->virtual_row)
		max_line_show = 0;
	else
		max_line_show = (max_line - pack->vdata->virtual_row);

	return (max_line_show);
}
