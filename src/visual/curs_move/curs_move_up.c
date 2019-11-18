#include "ft_select.h"

static inline void set_cursor_bottom_row(t_data_pack *pack)
{
	int max_line_show;
	int last_y;
	int last_x;

	max_line_show = get_max_line_show(pack);
	last_y = get_last_line_row(pack, max_line_show) - 1;
	last_x = get_last_line_col(pack, max_line_show, last_y);

	if (last_x != pack->cur_x)
		last_y = (last_y - 1) < 0 ? 0 : last_y - 1;
	pack->cur_y = last_y;
	set_cur_top_line(pack, max_line_show);
}

void curs_move_up(t_data_pack *pack)
{
	int max_line_data;
	int prev_line_y;
	int index;
	int y;

	y = pack->cur_y;
	max_line_data = get_max_data_line(pack);
	if(max_line_data < 2)
		return ;
	index = get_off(pack, pack->cur_x, pack->cur_y);
	prev_line_y = index - (pack->data_par_line);
	if((y - 1) >= 0 && prev_line_y >= 0)
	{
		pack->cur_y--;
		get_on(pack, pack->cur_x, pack->cur_y);
	}
	else
	{
		if((y - 1) < 0 && prev_line_y >= 0)
			set_cur_top_line(pack, pack->cur_top_line - 1);
		else if(prev_line_y < 0)
			set_cursor_bottom_row(pack);
		print_pack(pack);
	}
}
