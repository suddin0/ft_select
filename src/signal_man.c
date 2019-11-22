#include "ft_select.h"


void signal_test(int a)
{
	t_select *select;

	select = get_select();
	ft_dprintf(FT_STDERR_FD, "SIGNAL : %d            \n", a);
}

void scale_pack(t_data_pack *pack, UNUSED int old_index)
{
	int data_par_line;
	int data_index;
	int max_data_index;

	data_par_line = get_data_par_line(pack);
	data_index = get_data_index(pack);
	max_data_index = get_max_data_index(pack);
	/**
		if old cursor can be fit on the current screen then do notning just
		set the new cur_x and cur_y of the nex position
	**/
	if(old_index >= data_index && old_index < max_data_index)
	{
		int new_x = (old_index - pack->data_index) % pack->vdata->virtual_col;
		int new_y = (old_index - pack->data_index) / pack->vdata->virtual_col;
		pack->cur_x = new_x;
		pack->cur_y = new_y;
	}


	/**
		If the old cursor is not in the screen then calculate at what line the
		old cursor falls and set the top line so that it show the old cursor at
		the bottom
	**/
	// else
	// {
	//
	// }


	pack->data_par_line = data_par_line;
	pack->data_index = data_index;
	pack->max_data_index = max_data_index;
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
	old_index = index_of(&(select->data_pack), select->data_pack.cur_x, select->data_pack.cur_y);


	set_terminal_size(select);

	if(prev_row != select->vdata.row || prev_col != select->vdata.col)
		scale_pack(&(select->data_pack), old_index);
	/* Set up the proper line */

	clear_screen();
	print_pack(&(select->data_pack));
	update_footer(select);
	// ft_dprintf(select->data_fd, "Sigwinch\n");
	// ft_dprintf(select->data_fd, "Sigwinch\n");
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
