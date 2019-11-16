#include "ft_select.h"

int main(int argc, char **argv, UNUSED char **envp)
{
	t_select *select;
	int retval;

	retval = 0;
	select = get_select();
	if(init_select(select) == FT_SELECT_ERROR)
		return (1);
	if(arg_man(select, argc, argv) == FT_SELECT_ERROR)
		return (1);
	if(init_term(select) == FT_SELECT_ERROR)
		return (1);
	if(init_data(select, argc, argv) == FT_SELECT_ERROR)
		return (1);
	if(loop(select) == FT_SELECT_ERROR)
		retval = 1;
	free_select(select);
	return (retval);
}
