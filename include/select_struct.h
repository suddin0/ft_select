#ifndef FT_SELECT_STRUCT_H
# define FT_SELECT_STRUCT_H

# include <termcap.h>
# include <termios.h>
# include <unistd.h>
# include "select_types.h"
# include "select_defines.h"

typedef struct	s_argument_data
{
	char *data;
	int data_len;
	int hidden;
	int selected;
}				t_arg_data;

typedef struct	s_termcap_capacity
{
	char *cm;
	char *ti;
	char *te;
	char *vi;
	char *ve;

	/* arro kwys */
	char *key_up;
	char *key_dowm;
	char *key_left;
	char *key_right;

	char *key_delete;
	char *key_page_up;
	char *key_page_down;
	char *key_home;
	char *key_end;
	char *key_tab_left;
	char *key_scroll_up;
	char *key_scroll_down;
}				t_cap;

/**
*
**/

typedef struct	s_ft_select_internal_data
{
	char			*term_name;
	char			termcap_buff[TERMCAP_BUFF_SIZE];
	struct termios	termios_backup;
	struct termios	termios_setup;

	int				col;
	int				row;

	int				virtual_col;
	int				virtual_row;

	int				argv_start_index;
	int				max_arg_data;
	t_arg_data		*data;
	int				max_data_len;

	int				cur_x;
	int				cur_y;

	t_cap			cap;
	t_keytable 		key_seq_table[MAX_KEY_SEQ_TABLE_LEN];
	t_keytable 		key_table[MAX_KEY_TABLE_LEN];
}				t_select;

#endif
