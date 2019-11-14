#include "ft_select.h"

int set_arg_data(t_select *select, char **argv)
{
	int i;
	int arg_i;

	i = 0;
	arg_i = select->argv_start_index;
	select->data = (t_arg_data *)malloc(sizeof(t_arg_data) * (select->max_arg_data + 1));
	if(!(select->data))
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error: memory allocation : %s.\n", strerror(errno));
		return (FT_SELECT_ERROR);
	}

	/* Sort data here (or not) */
	while(i < select->max_arg_data)
	{
		select->data[i].data = argv[arg_i];
		select->data[i].data_len = ft_strlen(argv[arg_i]);
		if(select->data[i].data_len > select->max_data_len)
			select->max_data_len = select->data[i].data_len;
		select->data[i].hidden = FALSE;
		select->data[i].selected = FALSE;
		i++;
		arg_i++;
	}
	select->data[i].data = NULL;
	return (FT_SELECT_SUCCESS);
}
