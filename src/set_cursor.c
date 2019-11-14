#include "ft_select.h"

void set_cursor(t_select *select, int x, int y)
{
	t_select *sel;

	sel = select;
	if(!sel)
		sel = get_select();
	tputs(tgoto(sel->cap.cm, x, y), 1, ft_putc);
}
