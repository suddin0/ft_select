#include "ft_select.h"

int allocate_data(t_select *select)
{
	select->data = (t_arg_data *)malloc(sizeof(t_arg_data) *\
					(select->data_size + 1));
	if(!(select->data))
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error: memory allocation : %s.\n",\
			strerror(errno));
		return (FT_SELECT_ERROR);
	}
	select->data_pack.data = (t_arg_data **)malloc(sizeof(t_arg_data *) *\
								(select->data_size + 1));
	if(!(select->data))
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error: memory allocation : %s.\n",\
			strerror(errno));
		return (FT_SELECT_ERROR);
	}
	ft_memset(select->data_pack.data , 0, sizeof(t_arg_data *) *\
								(select->data_size + 1));
	return (FT_SELECT_SUCCESS);
}

/**
* NOTE: The order of initialization must be rpeserved for the following
* Variables:
* - select->vdata.data_par_line
* - select->vdata.data_index
* - select->vdata.max_data_index
**/


void copy_data_to_data_pack(t_select *select, t_data_pack *pack)
{
	int i;

	i = 0;
	while (i < select->data_size)
	{
		pack->data[i] = &(select->data[i]);
		i++;
	}
	pack->data_size = select->data_size;
	pack->max_str_len = select->max_str_len;

	pack->data_par_line = get_data_par_line(pack);
	pack->data_index = get_data_index(pack);
	pack->max_data_index = get_max_data_index(pack);
}

/**
* The following function takes all argv (argument) data, allocate enough memory
* and store them in the structure type `t_arg_data` and in this process it also
* initiate the structure elements to whatevet neecssery.
*
* NOTE: The `set_terminal_size` in the end of this function to update the
* structure `t_visual_data` (`vdata` element in `select`). Because at the end of
* This function we have the new value of our `datas` (arguments).
**/

int set_arg_data(t_select *select, char **argv)
{
	int i;
	int arg_i;

	i = 0;
	arg_i = select->argv_start_index;
	if(allocate_data(select) == FT_SELECT_ERROR)
		return (FT_SELECT_ERROR);

	/* Sort data here (or not) */
	while(i < select->data_size)
	{
		select->data[i].data = argv[arg_i];
		select->data[i].data_len = ft_strlen(argv[arg_i]);
		if(select->data[i].data_len > select->max_str_len)
			select->max_str_len = select->data[i].data_len;
		select->data[i].selected = FALSE;
		i++;
		arg_i++;
	}
	select->data[i].data = NULL;
	copy_data_to_data_pack(select, &(select->data_pack));
	return (FT_SELECT_SUCCESS);
}
