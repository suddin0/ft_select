#include "ft_select.h"


void escape_key_man(t_select *select, int seq, UNUSED int *loop_control)
{
	if(seq == SEQ_UNKNOWN)
		return ;
	select->key_seq_table[seq](select);
}
