#include "ft_select.h"
#include <ctype.h>

void reset_terminal()
{
	t_select *select;

	select = get_select();
	tputs(tgetstr("te", NULL), 1, ft_putc);
	tputs(tgetstr("ve", NULL), 1, ft_putc);
	tcsetattr(STDERR_FILENO, TCSANOW, &select->termios_backup);
}

int loop(UNUSED t_select *select)
{
	int rd;
	char data[READ_DATA_SIZE];

	int i = 0;
	int x = 0;
	int y = 0;

	char *cm = tgetstr("cm", NULL);;

	while((rd = read(FT_STDIN_FD, &data, READ_DATA_SIZE)) > 0)
	{
		// if(rd == 'q')
			// return (FT_SELECT_SUCCESS);
		data[rd] = 0;
		// ft_printf("--------------------\n");
		// while(i < rd)
		// {
		// 	if(isprint(data[i++]))
		// 		ft_printf("[%c] ", data[i]);
		// 	else
		// 		ft_printf("[%d] ", data[i]);
		// 	i++;
		// }
		// ft_printf("\n--------------------\n");
		if(data[0] == 'q')
		{
			reset_terminal();
			return (FT_SELECT_SUCCESS);
		}
		if(data[0] == 'x')
		{
			tputs(tgoto(cm, x, y), 1, ft_putc);
			x+= 10;
		}

		if(data[0] == 'y')
		{
			tputs(tgoto(cm, x, y), 1, ft_putc);
			y+= 10;
		}

		i = 0;
	}
	if(rd < 0)
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error: reading user input : %s.\n", strerror(errno));
		return (FT_SELECT_ERROR);
	}
	return (FT_SELECT_SUCCESS);
}




int main(int argc, char **argv, UNUSED char **envp)
{
	t_select *select;
	int retval;

	retval = 0;
	select = get_select();
	init_select(select);
	signal_man();
	if(arg_man(select, argc, argv) == FT_SELECT_ERROR)
		return (1);
	if(argument_len_check(argc) == FT_SELECT_ERROR)
	{
		ft_dprintf(FT_STDERR_FD"No data was provided\n");
		return (0);
	}
	if(init_term(select) == FT_SELECT_ERROR)
		return (1);
	if(set_arg_data(select, argv) == FT_SELECT_ERROR)
		return (1);
	show_all_data(select);
	if(loop(select) == FT_SELECT_ERROR)
		retval = 1;
	free_select(select);
	return (retval);
}
