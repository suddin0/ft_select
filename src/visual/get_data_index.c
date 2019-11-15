#include "ft_select.h"

int get_data_index(t_select *select)
{
	int index;

	index = select->vdata.cur_top_line * select->vdata.data_par_line;
	if(index > select->max_arg_data)
		index = 0;
	return (index);
}
