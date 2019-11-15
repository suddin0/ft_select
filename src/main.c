#include "ft_select.h"
#include <ctype.h>



void key_up(UNUSED t_select *select){}
void key_dowm(UNUSED t_select *select){}
void key_left(UNUSED t_select *select){}
void key_right(UNUSED t_select *select)
{
	// set_cursor(select, 0, 0);

	// tputs(select->cap.cd, 1, ft_putc);
	ft_dprintf(SELECT_DATA_FD, "Came here\n");
}
void key_delete(UNUSED t_select *select){}
void key_page_up(UNUSED t_select *select){}
void key_page_down(UNUSED t_select *select){}
void key_home(UNUSED t_select *select){}
void key_end(UNUSED t_select *select){}
void key_tab_left(UNUSED t_select *select){}
void key_scroll_up(UNUSED t_select *select){}
void key_scroll_down(UNUSED t_select *select){}

void key_seq_table_init(UNUSED t_select *select)
{
	select->key_seq_table[SEQ_KEY_UP]		= key_up;
	select->key_seq_table[SEQ_KEY_DOWN]		= key_dowm;
	select->key_seq_table[SEQ_KEY_LEFT]		= key_left;
	select->key_seq_table[SEQ_KEY_RIGHT]	= key_right;
	select->key_seq_table[SEQ_KEY_DELETE]	= key_delete;
	select->key_seq_table[SEQ_KEY_PAGE_UP]	= key_page_up;
	select->key_seq_table[SEQ_KEY_PAGE_DOWN]= key_page_down;
	select->key_seq_table[SEQ_KEY_HOME]		= key_home;
	select->key_seq_table[SEQ_KEY_END]		= key_end;
	select->key_seq_table[SEQ_KEY_TAB_LEFT]	= key_tab_left;
	select->key_seq_table[SEQ_SCROLL_UP]	= key_scroll_up;
	select->key_seq_table[SEQ_SCROLL_DOWN]	= key_scroll_down;
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
		ft_dprintf(FT_STDERR_FD, "No data was provided\n");
		return (0);
	}
	if(init_term(select) == FT_SELECT_ERROR)
		return (1);
	if(set_arg_data(select, argv) == FT_SELECT_ERROR)
		return (1);

	key_seq_table_init(select);
	show_all_data(select);
	if(loop(select) == FT_SELECT_ERROR)
		retval = 1;
	free_select(select);
	return (retval);
}
