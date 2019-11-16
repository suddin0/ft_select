#ifndef FT_SELECT_H
# define FT_SELECT_H

/*
** Some 42 libraries
**
** # include "libft.h"
** # include "ft_printf.h"
** # include "ft_getopt.h"
*/

# include "libft.h"
# include "ft_getopt.h"
# include "ft_getopt.h"
# include "keys.h"
# include "select_defines.h"
# include "select_struct.h"
# include "select_types.h"
# include "select_error_string.h"

# include <getopt.h> // delete it

# include <termcap.h>
# include <termios.h>
# include <unistd.h>

# include <errno.h>
# include <string.h>
# include <signal.h>

/**
* The following includes are used to use the function `oepn`
**/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/**
* To use ioctl(...)
**/

#include <sys/ioctl.h>

/*
** The following define `UNUSED` is used on parameter / varaibles that are there
** but not used. It  is possible to create function that have parameter and are
** not used beceause of how the proto type need to be.
*/

# ifndef UNUSED
#  define UNUSED __attribute__ ((unused))
# endif


/**
* initialisation related
**/

int			init_select(t_select *select);
int			arg_man(t_select *select, int argc, char **argv);
int			init_term(t_select *select);
int			set_arg_data(t_select *select, char **argv);
int			argument_len_check(int argc);
int			init_data(t_select *selectm, int argc, char **argv);


t_select	*get_select();
void		free_select(t_select *select);
void		signal_man();
void		set_terminal_size(t_select *select);
int			ft_putc(int c);
void		reset_terminal();
int			loop(UNUSED t_select *select);



/**
* Key related
**/

int			get_seq(t_cap cap, char *data);
void		escape_key_man( t_select *select, int seq, int *loop_control);
void		key_man(t_select *select, char key, int *loop_control);
void		key_seq_table_init(UNUSED t_select *select);

/**
* Everything related to visual
**/

void		print_data(t_data_pack *pack, t_arg_data *data, const unsigned char popt);

int			get_data_par_line(t_data_pack *pack);
int			get_data_index(t_data_pack *pack);
int			get_max_data_index(t_data_pack *select);
void		set_cursor(t_cap *cap, int x, int y);
int			index_of(t_data_pack *pack, int x, int y);
int			get_off(t_data_pack *pack, int x, int y);
int			get_on(t_data_pack *pack, int x, int y);
void		clear_screen();
void		set_cur_top_line(t_data_pack *pack, int line_nb);
int			get_max_data_line(t_data_pack *pack);
int			get_max_str_len(t_data_pack *pack);
void		print_pack(t_data_pack *pack);

void		curs_move_up(t_select *select);
void		curs_move_down(t_select *select);
void		curs_move_right(t_data_pack *pack);
void		curs_move_left(t_data_pack *pack);


#endif

/*
	The following options should be implimented :
	- color (yes, no)
	- color value
	- sort (yes, no)
	- reverse
	- row output
	- colon output
	- row output

*/
