#include "ft_select.h"

t_select *get_select()
{
	static t_select select;
	return (&select);
}
