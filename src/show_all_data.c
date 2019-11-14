#include "ft_select.h"


int ft_poutchar(int c)
{
	ft_putchar (c);
	return (c);
}

static inline void print_data(t_select *select, t_arg_data *data)
{
	if(!data && !(data->data))
		return ;

	// tputs(tgetstr("so", NULL), 1, ft_poutchar);
	// tputs(tgetstr("us", NULL), 1, ft_poutchar);
	ft_dprintf(FT_STDIN_FD, "%-*s", select->max_data_len, data->data);
	// tputs(tgetstr("se", NULL), 1, ft_poutchar);
	// tputs(tgetstr("ue", NULL), 1, ft_poutchar);
	ft_dprintf(FT_STDIN_FD, " ");

}

void show_all_data(t_select *select)
{
	int data_par_line;
	int print_count;
	int i;

	i = 0;
	print_count = 0;
	if(select->max_data_len >= select->col)
		data_par_line = 1;
	else
		data_par_line = select->col / (select->max_data_len + 1);
	while(i < select->max_arg_data)
	{
		if(select->data[i].hidden == FALSE)
		{
			print_data(select, &(select->data[i]));
			print_count++;
		}
		if(print_count % data_par_line == 0)
			ft_dprintf(FT_STDIN_FD, "\n");
		i++;
	}
}
