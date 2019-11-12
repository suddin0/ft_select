#include "ft_select.h"

void init_select(t_select *select)
{
	select->term_name = NULL;
	if(IS_UNIX)
		ft_memset(select->termcap_buff, 0, TERMCAP_BUFF_SIZE);
}
