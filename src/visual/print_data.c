#include "ft_select.h"

void print_data(t_data_pack *pack, t_arg_data *data, const unsigned char popt)
{
	if(popt & POPT_REVERSE)
		tputs(pack->cap->cap[CAP_MR], 1, ft_putc);
	if(data->selected)
	{
		tputs(pack->cap->cap[CAP_SO], 1, ft_putc);
		tputs(pack->cap->cap[CAP_US], 1, ft_putc);
	}

	ft_dprintf(pack->data_fd, "%-*s", pack->max_str_len, data->data);
	tputs(pack->cap->cap[CAP_ME], 1, ft_putc);
	ft_dprintf(pack->data_fd, "%*s", VISUAL_DATA_SPACING, "");
}
