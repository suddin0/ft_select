#include "ft_select.h"

int get_max_data_line(t_data_pack *pack)
{
	int max_line;

	if(pack->data_size == 0 || pack->data_par_line == 0)
		return (0);

	max_line = pack->data_size / pack->data_par_line;
	if((pack->data_size % pack->data_par_line) != 0)
		max_line++;
	return (max_line);
}
