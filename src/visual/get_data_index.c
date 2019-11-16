#include "ft_select.h"

int get_data_index(t_data_pack *pack)
{
	int index;

	index = pack->cur_top_line * pack->data_par_line;
	if(index >= pack->data_size)
		index = 0;
	return (index);
}
