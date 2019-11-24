#include "ft_select.h"

int init_data(t_select *select, int argc, char **argv)
{
	select->argv_start_index = *(get_optind());
	select->data_size = argc - select->argv_start_index;
	select->data_pack.vdata = &select->vdata;
	select->data_pack.cap = &select->cap;
	select->data_pack.data_fd = select->data_fd;

	if(set_arg_data(select, argv) == FT_SELECT_ERROR)
		return (FT_SELECT_ERROR);
	print_pack(&(select->data_pack), TRUE);
	update_footer(select);
	return (FT_SELECT_SUCCESS);
}
