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
	int selected;
}				t_arg_data;

/**
* The following structure is used to store the string of capacity that we use
* the function tputs(). The string is retreaved using the function tgetstr(...).
*
* We store the sting in this dedicated structure so we can use it in different
* functions and later we can `free(...)` the allocated memory for those strings.
**/

typedef struct	s_termcap_capacity
{
	char *cm;
	char *ti;
	char *vi;
	char *te;
	char *ve;
	char *cl;
	char *cd;
	char *mr;
	char *me;

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


typedef struct	s_visual_data
{
	int	col;
	int	row;

	int	virtual_col;
	int	virtual_row;


}				t_visual_data;

/**
*
* max_arg_data : the size of the array `data`
* max_data_len : the size of the largest string in all elements of `data` array.
* vdata : contains information about how this data is represented in screen.
**/
typedef struct	s_data_packat
{
	int				data_fd;
	t_arg_data		**data;
	int				data_size; // max_arg_data
	int				max_str_len; // max_data_len

	int				cur_x;
	int				cur_y;
	int				cur_top_line;

	int				data_par_line;
	int				data_index;
	int				max_data_index;
	t_visual_data	*vdata;
	t_cap			*cap;
}				t_data_pack;


/**
* The following structure is used to hold most of the program data that is
* needed to be stored and move around.
*
* The following members are used for :
*
* term_name			: The value of `TERM` environment variable.
*
* termcap_buff		: The buffer used to store termcap database data (only UNIX)
* termios_backup	: Backup information of default terminal setup (by termios)
* termios_setup		: The new terminal setup used with termios
*
* col				: Terminal Max colon (real value)
* row				: Terminal Max row (real value)
* virtual_col		: A vertual value tat represent an area for data to print
* virtual_row		: A vertual value tat represent an area for data to print
*
* argv_start_index	: Where arguments start in argv (after skiping options)
* max_arg_data		: Length of arguments (not counting options) passed by user
* data				: Array of structure containging the argument (not options)
* max_data_len		: The length (strlen) of the longest argument (for printing)
*
* cur_x				: At which option the cursor is in the current line
* cur_y				: At which line the curror is
* cur_top_line		: The line from we start to print in the weindow
*
* cap				: Structure containing information about terminal capacity
*
* key_seq_table		: A function table (jump table) containing function that are
*                     called when a particular key sequence is invoked (pressed)
* key_table			:A function table (jump table) containing function that are
*                     called when a particular key is invoked (pressed)
**/

typedef struct	s_ft_select_internal_data
{
	char			*term_name;
	char			termcap_buff[TERMCAP_BUFF_SIZE];
	int				data_fd;
	struct termios	termios_backup;
	struct termios	termios_setup;

	t_cap			cap;
	t_keytable 		key_seq_table[MAX_KEY_SEQ_TABLE_LEN];
	t_keytable 		key_table[MAX_KEY_TABLE_LEN];

	int				argv_start_index;
	t_arg_data		*data;
	int				data_size; // max_arg_data
	int				max_str_len; // max_data_len
	t_visual_data	vdata;

	t_data_pack		data_pack;
}				t_select;

#endif
