#include "ft_select.h"

static inline void print_data(t_select *select, t_arg_data *data, int x, int y)
{
	if(!data && !(data->data))
		return ;

	if(x == select->vdata.cur_x && y == select->vdata.cur_y)
	{
		tputs(select->cap.mr, 1, ft_putc);
	}

	// tputs(tgetstr("so", NULL), 1, ft_poutchar);
	// tputs(tgetstr("us", NULL), 1, ft_poutchar);
	ft_dprintf(SELECT_DATA_FD, "%-*s", select->max_data_len, data->data);
	// tputs(tgetstr("se", NULL), 1, ft_poutchar);
	// tputs(tgetstr("ue", NULL), 1, ft_poutchar);
	tputs(select->cap.me, 1, ft_putc);
	ft_dprintf(SELECT_DATA_FD, " ");


}



void show_all_data(t_select *select)
{
	int data_index;
	int x = 0;
	int y = 0;

	data_index = select->vdata.data_index;
	while(data_index < select->vdata.max_data_index)
	{
		print_data(select, &(select->data[data_index]), x, y);
		if(x + 1 >= select->vdata.data_par_line)
		{
			y++;
			x = 0;
			ft_dprintf(SELECT_DATA_FD, "\n");
		}
		else
			x++;
		data_index++;
	}
}
