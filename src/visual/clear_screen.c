#include "ft_select.h"

void clear_screen()
{
	t_select *select;

	select = get_select();
	tputs(select->cap.cap[CAP_CL], 1, ft_putc);
	set_cursor(&(select->cap), 0, 0);
}
