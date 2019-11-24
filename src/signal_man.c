#include "ft_select.h"


void signal_test(int a)
{
	t_select *select;

	select = get_select();
	ft_dprintf(FT_STDERR_FD, "SIGNAL : %d            \n", a);
	reset_terminal();
	free_select(select);
	exit(1);
}

/**
* The following function has the goal of recalculating all the important
* variables such as How many data par line can we fit now, Which sould be the
* first index so that the current x and y are in  it's proper place, etc.
*
* once it hets all the data that is appropriate for the current terminal size
* it then verify if the current index (where the cursore is) is inside the
* visible area of the terminal or it goes too far, if it is inside then we
* assigne the newly calculated X and Y position else we set the new value
* of the current top line so it start printing from the line which makes the
* last line our nez Y positon.
**/

void scale_pack(t_data_pack *pack, int old_index)
{
	int new_x;
	int new_y;

	set_cur_top_line(pack, 0);
	pack->data_par_line = get_data_par_line(pack);
	pack->data_index = get_data_index(pack);
	pack->max_data_index = get_max_data_index(pack);

	new_x = old_index % pack->data_par_line;
	new_y = old_index / pack->data_par_line;

	if(new_y >= pack->vdata->virtual_row)
	{
		set_cur_top_line(pack, new_y - (pack->vdata->virtual_row - 1));
		new_y = pack->vdata->virtual_row - 1;
	}
	pack->cur_x = new_x;
	pack->cur_y = new_y;
}

void sigwinch_handler(UNUSED int sig)
{
	t_select *select;
	int prev_col;
	int prev_row;
	int old_index;

	select = get_select();
	prev_col = select->vdata.col;
	prev_row = select->vdata.row;
	old_index = index_of(&(select->data_pack), select->data_pack.cur_x,\
		select->data_pack.cur_y);

	set_terminal_size(select);

	if(prev_row != select->vdata.row || prev_col != select->vdata.col)
		scale_pack(&(select->data_pack), old_index);
	/* Set up the proper line */
	//
	clear_screen();
	print_pack(&(select->data_pack), FALSE);
	update_footer(select);
}


void signal_man()
{
	signal(SIGWINCH,	sigwinch_handler);
	signal(SIGABRT,		signal_test);
	signal(SIGINT,		signal_test);
	signal(SIGSTOP,		signal_test);
	signal(SIGCONT,		signal_test);
	signal(SIGTSTP,		signal_test);
	signal(SIGKILL,		signal_test);
	signal(SIGQUIT,		signal_test);
}
