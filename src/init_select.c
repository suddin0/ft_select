#include "ft_select.h"

void init_select(t_select *select)
{
	select->term_name = NULL;
	if(IS_UNIX)
		ft_memset(select->termcap_buff, 0, TERMCAP_BUFF_SIZE);
	select->col = 0;
	select->row = 0;
	select->argv_start_index = 0;
	select->max_arg_data = 0;
	select->data = NULL;
	select->max_data_len = 0;
	select->cursor = 0;
}
