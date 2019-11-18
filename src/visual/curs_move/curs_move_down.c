#include "ft_select.h"

void curs_move_down(t_data_pack *pack)
{
	int max_line_data;
	int next_line_y;
	int index;
	int y;

	y = pack->cur_y;
	max_line_data = get_max_data_line(pack);
	if(max_line_data < 2)
		return ;
	index = get_off(pack, pack->cur_x, pack->cur_y);
	next_line_y = index + pack->data_par_line;
	if((y + 1) < pack->vdata->virtual_row && next_line_y < pack->data_size)
	{
		pack->cur_y++;
		get_on(pack, pack->cur_x, pack->cur_y);
	}
	else
	{
		if((y + 1) >= pack->vdata->virtual_row && next_line_y < pack->data_size)
			set_cur_top_line(pack, pack->cur_top_line + 1);
		else if(next_line_y >= pack->data_size)
		{
			pack->cur_y = 0;
			set_cur_top_line(pack, 0);
		}
		print_pack(pack);
	}
}
