#include "ft_select.h"

int get_max_data_index(t_data_pack *pack)
{
	int max;

	max =  pack->data_index + (pack->data_par_line * pack->vdata->virtual_row);
	if(max > pack->data_size)
		max = pack->data_size;
	return (max);
}
