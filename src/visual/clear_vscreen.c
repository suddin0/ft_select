#include "ft_select.h"

void clear_vscreen()
{
	t_select *select;

	select = get_select();
	set_cursor(&(select->cap), 0, select->vdata.virtual_row);
	tputs(select->vdata.last_vline, 1, ft_putc);
	set_cursor(&(select->cap), 0, 0);
}
