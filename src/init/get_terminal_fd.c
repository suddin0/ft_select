#include "ft_select.h"


static inline int get_ttyslot()
{
	int slot;

	slot = ttyslot();
	if(IS_UNIX && !IS_LINUX)
	{
		if(slot == 0)
			return (FT_SELECT_ERROR);
	}
	else
	{
		if(slot < 0)
			return (FT_SELECT_ERROR);
	}
	return (slot);
}

static inline char *get_ttyname()
{
	int slot;
	int error_no;
	char *name;

	error_no = 0;
	name = NULL;
	if((slot = get_ttyslot()) == FT_SELECT_ERROR)
		error_no = errno;

	if((name = ttyname(slot)))
		return(name);
	else if((name = ttyname(FT_STDIN_FD)))
		return (name);
	else if((name = ttyname(FT_STDOUT_FD)))
	 	return (name);
	else if((name = ttyname(FT_STDERR_FD)))
		return (name);
	else
	{
		if(error_no)
			ft_dprintf(FT_STDERR_FD, "[-] Error getting ttyslot (%d) : %s\n", slot);
		ft_dprintf(FT_STDERR_FD, "[-] Error getting ttyname : %s\n", strerror(errno));
		return (NULL);
	}
}

int get_terminal_fd(t_select *select)
{
	int fd;
	char *tty_name;


	tty_name = get_ttyname();

	if(!tty_name)
		return (FT_SELECT_ERROR);
	fd = open(tty_name, O_RDWR);
	if(fd < 0)
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error opening tty (%s) : %s\n", ttyname, strerror(errno));
		return (FT_SELECT_ERROR);
	}
	select->data_fd = fd;
	return (FT_SELECT_SUCCESS);
}
