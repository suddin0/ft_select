#include "ft_select.h"

void reset_terminal()
{
	t_select *select;

	select = get_select();
	tputs(select->cap.te, 1, ft_putc);
	// tputs(select->cap.ve, 1, ft_putc);
	tcsetattr(STDERR_FILENO, TCSANOW, &select->termios_backup);
}
