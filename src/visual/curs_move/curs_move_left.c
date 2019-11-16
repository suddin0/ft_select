#include "ft_select.h"

/**
* The function `curs_move_right` is used to visually and internally go to the
* next data. To do si the function first remove where it is currently (to remove
* means to not highlight the text). and goes to the next data (highlight it).
*
* When transitioning to the next data there can be 4 possible options:
*
* - 1 We are currently not at the last data of the line nor are we at the end of
*   our list of data so we can stay in the same line and we can just go to the
*   next data in the same line

* - 2 We are are currently at the end of the line and we are NOT at the last row
*   row (the most bottom position) of the terminal then we just set out `X` to 0
*   and we add `1` to out `Y` position.
*
* - 3 We are are currently at the end of the line and we are AT the last row. If
*   this is the case we set our `X` position to 0 and we add 1 to the `start
*   line` (the line where we start printing)  so that there is a `scroll` efect.
*   in this situation we do not change the `Y` position as we are still going to
*   be att the last `row` (the most bottom position)
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

int get_max_line_show(t_data_pack *pack)
{
	int max_line;
	int max_line_show;

	max_line = get_max_data_line(pack);
	/* if whe whole screen contain all data then do not change line */
	if(max_line < pack->vdata->virtual_row)
		max_line_show = 0;
	else
		max_line_show = (max_line - pack->vdata->virtual_row);

	return (max_line_show);
}

int get_last_line_row(t_data_pack *pack, int max_line_show)
{
	int max_line;
	int row;

	max_line = get_max_data_line(pack);
	row  = max_line - max_line_show;
	return (row > pack->vdata->virtual_row ? row - 1 : row);
}

int get_last_line_col(t_data_pack *pack, int max_line_show, int last_row)
{
	int index;
	int col;

	index = (max_line_show * pack->data_par_line) + (pack->data_par_line * last_row);
	col = (pack->data_size - index) - 1;
	return (col < 0 ? 0 : col);
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
