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

void curs_move_right(t_data_pack *pack)
{
	int x;
	int y;
	int index;

	if(pack->data_size < 2)
		return ;
	x = pack->cur_x;
	y = pack->cur_y;

	index = get_off(pack, x, y);

	if((x + 1) < pack->data_par_line && (index + 1) < pack->data_size
		&& y < pack->vdata->virtual_row)
	{
		(pack->cur_x)++;
		 get_on(pack, pack->cur_x, pack->cur_y);

	}
	else if((y + 1) < pack->vdata->virtual_row && (index + 1) < pack->data_size)
	{
		pack->cur_x = 0;
		(pack->cur_y)++;
		get_on(pack, pack->cur_x, pack->cur_y);
	}
	else
	{
		if ((y + 1) >= pack->vdata->virtual_row && (index + 1) < pack->data_size)
		{
			pack->cur_x = 0;
			set_cur_top_line(pack, pack->cur_top_line + 1);

		}
		else if((index + 1) >= pack->data_size)
		{
			pack->cur_x = 0;
			pack->cur_y = 0;
			set_cur_top_line(pack, 0);
		}
		print_pack(pack, TRUE);
	}
}
