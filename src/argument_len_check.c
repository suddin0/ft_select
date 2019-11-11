#include "ft_select.h"

int argument_len_check(int argc)
{
	int index;

	index = *(get_optind());
	if (index >= argc || argc  < 2)
		return (FT_SELECT_ERROR);
	return(FT_SELECT_SUCCESS);
}
