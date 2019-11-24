#include "ft_select.h"

void print_pack(t_data_pack *pack, int clear_screen)
{
	int data_index;
	int x = 0;
	int y = 0;

	data_index = pack->data_index;
	if(clear_screen)
		clear_vscreen();
	while(data_index < pack->max_data_index)
	{
		if(x == pack->cur_x && y == pack->cur_y)
			print_data(pack, pack->data[data_index], POPT_REVERSE);
		else
			print_data(pack, pack->data[data_index], POPT_NO_OPT);
		if(x + 1 >= pack->data_par_line)
		{
			y++;
			x = 0;
			ft_dprintf(pack->data_fd, "\n");
		}
		else
			x++;
		data_index++;
	}
}
