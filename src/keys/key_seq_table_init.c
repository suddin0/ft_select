#include "ft_select.h"

void key_up(UNUSED t_select *select)
{
	curs_move_up(&(select->data_pack));
}


void key_dowm(UNUSED t_select *select)
{
	curs_move_down(&(select->data_pack));
}
void key_left(t_select *select)
{
	curs_move_left(&(select->data_pack));
}
void key_right(UNUSED t_select *select)
{
	curs_move_right(&(select->data_pack));
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
