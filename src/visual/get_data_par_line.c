#include "ft_select.h"

int get_data_par_line(t_data_pack *pack)
{
	int data_par_line;
	int max_data_len;

	max_data_len = get_max_str_len(pack);
	if(pack->max_str_len >= pack->vdata->virtual_col)
		data_par_line = 1;
	else
		data_par_line = pack->vdata->virtual_col / (max_data_len + VISUAL_DATA_SPACING);
	return (data_par_line);
}
