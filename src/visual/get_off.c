#include "ft_select.h"

int get_off(t_data_pack *pack, int x, int y)
{
	int index;
	int max_str_len;
	int nx;
	int ny;

	index = index_of(pack, x, y);
	if(index == VISUAL_OUT_OF_BOUND || index == INDEX_OUT_OF_BOUND)
		return (index);

	max_str_len = get_max_str_len(pack);
	nx = x * max_str_len;
	ny = y;
	set_cursor(pack->cap, nx, ny);
	print_data(pack, pack->data[index], POPT_NO_OPT);
	return(index);
}
