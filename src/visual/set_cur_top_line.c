#include "ft_select.h"

void set_cur_top_line(t_data_pack *pack, int line_nb)
{
	int max_line;

	if(pack->data_size == 0 || pack->data_par_line == 0)
		return ;
	max_line = get_max_data_line(pack);
	if((pack->data_size % pack->data_par_line) != 0)
		max_line++;
	if(line_nb < 0 || line_nb >= max_line)
		return ;
	pack->cur_top_line = line_nb;
	pack->data_index = get_data_index(pack);
	pack->max_data_index = get_max_data_index(pack);
}
