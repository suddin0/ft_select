#include "ft_select.h"

int index_of(t_data_pack *pack, int x, int y)
{
	int index;

	index = 0;
	if(x >= pack->data_par_line || y > pack->vdata->virtual_row)
		return (VISUAL_OUT_OF_BOUND);

	index = pack->data_index + (pack->data_par_line * y) + x;
	if(index >= pack->data_size)
		return (INDEX_OUT_OF_BOUND);
	return (index);
}
