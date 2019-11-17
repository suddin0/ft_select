#include "ft_select.h"

int get_last_line_col(t_data_pack *pack, int max_line_show, int last_row)
{
	int index;
	int col;

	index = (max_line_show * pack->data_par_line) +\
				(pack->data_par_line * last_row);
	col = (pack->data_size - index) - 1;
	return (col < 0 ? 0 : col);
}
