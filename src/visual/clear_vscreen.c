#include "ft_select.h"

void clear_vscreen()
{
	t_select *select;

	select = get_select();
	set_cursor(&(select->cap), 0, 0);
	tputs(tgoto(select->cap.cap[CAP_REM_N_LINE_BEFORE],\
		select->vdata.virtual_row, select->vdata.virtual_row), 1, ft_putc);
	tputs(tgoto(select->cap.cap[CAP_PUT_N_LINE_AFTER],\
		select->vdata.virtual_row, select->vdata.virtual_row), 1, ft_putc);

	set_cursor(&(select->cap), 0, 0);
}
