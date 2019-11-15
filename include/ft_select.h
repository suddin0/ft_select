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

# include <getopt.h> // delete it

# include <termcap.h>
# include <termios.h>
# include <unistd.h>

# include <errno.h>
# include <string.h>
# include <signal.h>

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
* The following typedef is used to create function pointer for key precess and
* key sequences.
**/


t_select	*get_select();
int			argument_len_check(int argc);
int			arg_man(t_select *select, int argc, char **argv);
int			init_term(t_select *select);
void		init_select(t_select *select);
void		free_select(t_select *select);
void		signal_man();
void		set_terminal_size(t_select *select);
void		show_all_data(t_select *select);
int			set_arg_data(t_select *select, char **argv);
int			ft_putc(int c);
void		reset_terminal();
void		set_cursor(t_select *select, int x, int y);
int			loop(UNUSED t_select *select);


/**
* Key related
**/
int			get_seq(t_cap cap, char *data);
void		escape_key_man( t_select *select, int seq, int *loop_control);
void		key_man(t_select *select, char key, int *loop_control);

/**
* Everything related to visual
**/

int			get_data_par_line(t_select *select);
int			get_data_index(t_select *select);
int			get_max_data_index(t_select *select);


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
