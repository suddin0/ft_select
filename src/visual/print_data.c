#include "ft_select.h"

void print_data(t_data_pack *pack, t_arg_data *data, const unsigned char popt)
{
	int width;
	int precision;

	width = pack->data_par_line > 1 ? pack->max_str_len : pack->vdata->virtual_col;
	precision = pack->vdata->virtual_col;
	if(popt & POPT_REVERSE)
		tputs(pack->cap->cap[CAP_MR], 1, ft_putc);
	if(data->selected)
	{
		tputs(pack->cap->cap[CAP_SO], 1, ft_putc);
		tputs(pack->cap->cap[CAP_US], 1, ft_putc);
	}

	ft_dprintf(pack->data_fd, "%-*.*s", width, precision, data->data);
	tputs(pack->cap->cap[CAP_ME], 1, ft_putc);

	if(pack->data_par_line > 1)
		ft_dprintf(pack->data_fd, "%*s", VISUAL_DATA_SPACING, "");
}
