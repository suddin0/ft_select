#include "ft_select.h"

int get_last_line_row(t_data_pack *pack, int max_line_show)
{
	int max_line;
	int row;

	max_line = get_max_data_line(pack);
	row  = max_line - max_line_show;
	return (row > pack->vdata->virtual_row ? row - 1 : row);
}
