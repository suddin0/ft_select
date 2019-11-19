#include "ft_select.h"

void key_man(UNUSED t_select *select, char key, int *loop_control)
{
	// ft_dprintf(SELECT_DATA_FD, "---Normal key---\n");
	// ft_dprintf(SELECT_DATA_FD, "[%d] \n", key);
	// ft_dprintf(SELECT_DATA_FD, "---------------------\n");

	// if(key == KEY_ESC || key == KEY_Q || key == KEY_SHIFT_Q\
	// 	|| key == KEY_CTRL_C || key == KEY_CTRL_D)
	// {
	// 	reset_terminal();
	// 	*loop_control = FALSE;
	// }
	if(key == KEY_Q)
	{
		reset_terminal();
		*loop_control = FALSE;
	}
	if(key == KEY_G)
	{
		set_cursor(&(select->cap), 0, 0);
		// if(!tgetstr("DL", NULL))
		// 	ft_dprintf(select->data_fd, "`DL` is NULLLL   \n");
		// else
		// {
			// tputs(tgetstr("DL", NULL), 10, ft_putc);
			tputs(tgoto(tgetstr("DL", NULL), select->vdata.virtual_row, select->vdata.virtual_row), 1, ft_putc);
			// tputs(tgetstr("al", NULL), 1, ft_putc);

		// }
	}
	if(key == KEY_SPACEC)
		select_data(&(select->data_pack));
}
