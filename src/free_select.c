#include "ft_select.h"

void free_select(t_select *select)
{
	if(select->data)
	{
		free(select->data);
		select->data = NULL;
	}
}
