#include "ft_select.h"

void set_select_to_zero(t_select *select)
{
	select->term_name = NULL;
	select->data_fd = -1;
	if(IS_UNIX)
		ft_memset(select->termcap_buff, 0, TERMCAP_BUFF_SIZE);

	select->argv_start_index = 0;
	select->data_size = 0;
	select->data = NULL;
	select->max_str_len = 0;

	ft_memset(&(select->data_pack), 0, sizeof(t_data_pack));
	ft_memset(&(select->cap), 0, sizeof(t_cap));
}

int get_ttyslot()
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

char *get_ttyname()
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

int init_select(t_select *select)
{
	set_select_to_zero(select);
	if(get_terminal_fd(select) == FT_SELECT_ERROR)
		return (FT_SELECT_ERROR);
	signal_man();
	key_seq_table_init(select);
	return (FT_SELECT_SUCCESS);
}
