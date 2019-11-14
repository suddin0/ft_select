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
* The following define is used with the function `tgetent`. This function
* require the first parameter to either be a buffer (of enough length) or NULL
* depending in the library version. GNU termcap do not require any buffer as
* it store datas internally
**/

#ifdef unix
#  define IS_UNIX 1
#  define TERMCAP_BUFF_SIZE 2048
#else
#  define IS_UNIX 0
#  define TERMCAP_BUFF_SIZE 0
#endif

# if !defined(FALSE)
#  define FALSE 0
# endif

# if !defined(TRUE)
#  define TRUE 1
# endif

#define MAX_LONGOPT 2
#define MAX_SHORTOPT 10

#define FT_SELECT_ERROR -1
#define FT_SELECT_SUCCESS 0

#define READ_DATA_SIZE 10


typedef struct	s_argument_data
{
	char *data;
	int data_len;
	int hidden;
	int selected;
}				t_arg_data;

typedef struct	s_ft_select_internal_data
{
	char	*term_name;
	char	termcap_buff[TERMCAP_BUFF_SIZE];
	struct termios	termios_backup;
	struct termios	termios_setup;

	int				col;
	int				row;

	int				argv_start_index;
	int				max_arg_data;
	t_arg_data		*data;
	int				max_data_len;

	int				cursor;
}				t_select;


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
