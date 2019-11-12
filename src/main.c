#include "ft_select.h"

int main(int argc, char **argv, UNUSED char **envp)
{
	t_select select;

	init_select(&select);
	if(arg_man(argc, argv) == FT_SELECT_ERROR)
		return (1);
	if(argument_len_check(argc) == FT_SELECT_ERROR)
	{
		ft_printf("No data was provided\n");
		return (0);
	}
	if(init_term(&select) == FT_SELECT_ERROR)
		return (1);

	while(1);
	return 0;
}
