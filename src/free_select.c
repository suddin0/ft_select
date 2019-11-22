#include "ft_select.h"

void free_cap(t_cap *cap)
{
	int i;

	i = 0;
	if(!cap)
		return ;
	while(i < CAP_MAX_SIZE)
	{
		if(cap->cap[i])
		{
			free(cap->cap[i]);
			cap->cap[i] = NULL;
		}
		i++;
	}
}

void free_select(t_select *select)
{
	if(select->data_pack.data)
	{
		free(select->data_pack.data);
		select->data_pack.data = NULL;
	}
	if(select->data)
	{
		free(select->data);
		select->data = NULL;
	}
	if(select->data_fd != -1)
		close(select->data_fd);

	free_cap(&(select->cap));
}
