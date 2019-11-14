#include "ft_select.h"

void free_select(t_select *select)
{
	if(select->data)
	{
		free(select->data);
		select->data = NULL;
	}

	if(select->cap.cm)
		free(select->cap.cm);
	if(select->cap.ti)
		free(select->cap.ti);
	if(select->cap.vi)
		free(select->cap.vi);
}
