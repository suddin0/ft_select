#include "ft_select.h"

int get_max_data_index(t_select *select)
{
	int max;

	max =  select->vdata.data_index + (select->vdata.data_par_line *\
			select->vdata.virtual_row);
	if(max > select->max_arg_data)
		max = select->max_arg_data;
	return (max);
}
