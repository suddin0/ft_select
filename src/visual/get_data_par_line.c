#include "ft_select.h"

int get_data_par_line(t_select *select)
{
	int data_par_line;

	if(select->max_data_len >= select->vdata.virtual_col)
		data_par_line = 1;
	else
		data_par_line = select->vdata.virtual_col / (select->max_data_len + 1);
	return (data_par_line);
}
