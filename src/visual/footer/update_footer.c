#include "ft_select.h"

void print_flesh(t_select *select)
{
	ft_dprintf(select->data_fd, "\e[0m\e[30;48;5;6m\e[38;5;82m\ue0b0\e[8m", select->data_size);
}

void update_footer(t_select *select)
{
	if(select->footer.active == FALSE)
		return ;
	set_cursor(&(select->cap), 0, select->vdata.virtual_row);
	ft_dprintf(select->data_fd, "\e[30;48;5;82m total data :%d\e[0m", select->data_size);
	print_flesh(select);
	ft_dprintf(select->data_fd, "\e[0m");
	ft_dprintf(select->data_fd, "\e[30;48;5;6m selected data %d\e[0m", 0);
	print_flesh(select);
	ft_dprintf(select->data_fd, "\e[0m");
	ft_dprintf(select->data_fd, "visible data %d",select->data_size);
	print_flesh(select);
	ft_dprintf(select->data_fd, "\e[0m");

}
/*

Total data :
selected data :
deleted data :

line, X
TOP,BOT,All XX%

*/
// \e[30;48;5;90m
