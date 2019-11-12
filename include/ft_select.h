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

# include <getopt.h> // delete it

# include <termcap.h>
# include <termios.h>
# include <unistd.h>

# include <errno.h>
# include <string.h>

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

#define MAX_LONGOPT 2
#define MAX_SHORTOPT 10

#define FT_SELECT_ERROR -1
#define FT_SELECT_SUCCESS 0

typedef struct	s_ft_select_internal_data
{
	char	*term_name;
	char	termcap_buff[TERMCAP_BUFF_SIZE];
	struct termios	termios_backup;
	struct termios	termios_setup;
}				t_select;


int		argument_len_check(int argc);
int		arg_man(int argc, char **argv);
int		init_term(t_select *select);
void	init_select(t_select *select);


#endif
