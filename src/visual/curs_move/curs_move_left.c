#include "ft_select.h"

/**
* The function `curs_move_left` is used to visually and internally go to the
* previous data. To do so the function first remove where it is currently (to
* remove means to not highlight the text). and goes to the previous data
* (highlight it).
*
* When transitioning to the previous data there can be 4 possible options:
*
* - 1 We are currently not at the first data of the line nor are we at the end
*   of our list of data so we can stay in the same line and we can just go to
*   the previous data in the same line.

* - 2 We are are currently at the begining of the line and we are NOT at the
*   first row  (the most top position) of the terminal then we just set out `X`
*   to `max_data_parline - 1` (-1 cause it start counting at 0) And we add `-1`
*   to out `Y` position.
*
* - 3 We are are currently at the begining of the line and we are AT the first
*   row. If this is the case we set our `X` position to the number of element
*   that the last line can contain (because the last line might not contain
*   whatever `max_data_parline` number of data. It can be less) and we add
*   whatever line number that can fit the most data including the `LAST` line
*   of our list` (the line where we start printing)  so that we do not show only
*   one line of data at the top of screen (caus it's dumb to do so...).
*   In this situation we do change the `Y` position so it indicate the last
*   line. At this point we are indicating the last line in the `Y` position and
*   the last data at the `X` positon.
*
* - 4 We are at the end of the `data` list. We must go to the beginning of the
*   list and for that we change the `X` position to 0 and `Y` position to 0.
*   It is possible that the start of the list is not visible in the current
*   screen (it mught be too high up) thus you must set the `start line` to 0
*
**/

static inline int move_inside_screen(t_data_pack *pack, int index, int x, int y)
{
	if((x - 1) >= 0 && (index - 1) >= 0	&& y >= 0)
	{
		(pack->cur_x)--;
		 get_on(pack, pack->cur_x, pack->cur_y);
		 return (TRUE);
	}
	else if((y - 1) >= 0 && (index - 1) >= 0)
	{
		pack->cur_x = pack->data_par_line - 1;
		(pack->cur_y)--;
		get_on(pack, pack->cur_x, pack->cur_y);
		return (TRUE);
	}
	return (FALSE);
}


static inline void move_outside_screen(t_data_pack *pack, int index, int y)
{
	int max_line_show;
	int last_x;
	int last_y;

	max_line_show = 0;
	last_x = 0;
	last_y = 0;
	if ((y - 1) < 0 && (index - 1) >= 0)
	{
		pack->cur_x = pack->data_par_line - 1;
		set_cur_top_line(pack, pack->cur_top_line - 1);
	}
	else if((index - 1) < 0)
	{
		max_line_show = get_max_line_show(pack);
		last_y = get_last_line_row(pack, max_line_show) - 1;
		last_x = get_last_line_col(pack, max_line_show, last_y);
		pack->cur_x = last_x;
		pack->cur_y = last_y;
		set_cur_top_line(pack, max_line_show);
	}
	print_pack(pack);
}


void curs_move_left(t_data_pack *pack)
{
	int x;
	int y;
	int index;

	if(pack->data_size < 2)
		return ;
	x = pack->cur_x;
	y = pack->cur_y;

	index = get_off(pack, x, y);
	if(move_inside_screen(pack, index, x, y))
		return ;
	else
		move_outside_screen(pack, index, y);
}
