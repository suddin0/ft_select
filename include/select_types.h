#ifndef FT_SELECT_TYPES_H
# define FT_SELECT_TYPES_H

# include "select_struct.h"

typedef struct s_ft_select_internal_data t_re_select;

/**
* The following typedef is used to create function pointer for key precess and
* key sequences.
**/

typedef void (*t_keytable)(t_re_select *);

#endif
