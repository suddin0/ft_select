#include "ft_select.h"

void reset_terminal()
{
	t_select *select;

	select = get_select();
	set_cursor(&(select->cap), 0, 0);
	tputs(select->cap.cap[CAP_TE], 1, ft_putc);
	tputs(select->cap.cap[CAP_VE], 1, ft_putc);
	tcsetattr(select->data_fd, TCSANOW, &select->termios_backup);
}
