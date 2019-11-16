#include "ft_select.h"

int ft_putc(int c)
{
	t_select *select;

	select = get_select();
	return (write(select->data_fd, &c, 1));
}
