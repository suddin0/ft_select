#include "ft_select.h"

void clear_footer(t_select *select)
{
	set_cursor(&(select->cap), 0, select->vdata.virtual_row);
	tputs(select->cap.cap[CAP_DELETE_LINE], 1, ft_putc);
}
