#include "ft_select.h"

void set_cursor(t_cap *cap, int x, int y)
{
	t_select *select;

	if(!cap)
	{
		select = get_select();
		cap = &(select)->cap;
	}
	tputs(tgoto(cap->cm, x, y), 1, ft_putc);
}
