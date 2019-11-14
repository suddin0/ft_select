#include "ft_select.h"

void set_terminal_size(t_select *select)
{
	struct winsize w;

	ioctl(FT_STDIN_FD, TIOCGWINSZ, &w);
	select->row = w.ws_row;
	select->col =  w.ws_col;
}
