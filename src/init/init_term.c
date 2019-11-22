#include "ft_select.h"

static int init_termios(t_select *select)
{
	if(!isatty(select->data_fd))
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : The input filedescriptor");
		ft_dprintf(FT_STDERR_FD, " is not a terminal.\n");
		return (FT_SELECT_ERROR);
	}
	if(tcgetattr(select->data_fd, &(select->termios_setup))\
		|| tcgetattr(select->data_fd, &(select->termios_backup)))
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : unable to get terminal infor");
		ft_dprintf(FT_STDERR_FD, "mations (termios) : %s.\n", strerror(errno));
		return (FT_SELECT_ERROR);
	}
	select->termios_setup.c_lflag =  ~(ICANON | ECHO);
	// select->termios_setup.c_lflag =  ~(ECHO);
	select->termios_setup.c_cc[VMIN] = 1;
	select->termios_setup.c_cc[VTIME] = 0;
	if(tcsetattr(select->data_fd, TCSANOW, &select->termios_setup))
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : %s\n", ERR_TERMSETTING);
		return (FT_SELECT_ERROR);
	}
	return (FT_SELECT_SUCCESS);
}


static inline int init_cap(t_cap *cap)
{
	int capacity;
	int flag;
	int ret;

	capacity = 0;
	flag = 0;
	ret = FT_SELECT_SUCCESS;

	while(capacity < CAP_MAX_SIZE)
	{
		cap->cap[capacity] = tgetstr(cap->name[capacity], NULL);
		if(cap->mand[capacity] == TRUE && !(cap->cap[capacity]))
		{
			ft_dprintf(FT_STDERR_FD, "[-] Error : The flag `%s'", cap->name[capacity]);
			ft_dprintf(FT_STDERR_FD, " (%s) is not present ", cap->desc[capacity]);
			ft_dprintf(FT_STDERR_FD, "(in termcap db) for your terminal.\n");
			ret = FT_SELECT_ERROR;
		}
		capacity++;
	}
	return (ret);
}


static int init_termcap(t_select *select)
{
	int success;

	select->term_name = getenv ("TERM");
	if(!select->term_name)
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : %s\n%s\n", ERR_TENV, ERR_TINIT);
		return (FT_SELECT_ERROR);
	}
	if(IS_UNIX)
		success = tgetent (select->termcap_buff, select->term_name);
	else
		success = tgetent (NULL, select->term_name);
	if(success < 0)
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : %s\n", ERR_ACC_DB);
		return (FT_SELECT_ERROR);
	}
	else if(success == 0)
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : %s`%s`.\n", ERR_TENTRY, select->term_name);
		return (FT_SELECT_ERROR);
	}
	if(init_cap(&(select->cap)) == FT_SELECT_ERROR)
		return (FT_SELECT_ERROR);

	return (FT_SELECT_SUCCESS);
}


void set_footer(t_select *select, t_footer *footer)
{
	// if terminal is too small then do not show the dumd thing
	if(select->vdata.col < 2)
		footer->active = FALSE;
	else
		footer->active = TRUE;
}

int init_term(t_select *select)
{
	if(init_termios(select) == FT_SELECT_ERROR)
		return (FT_SELECT_ERROR);
	if(init_termcap(select) == FT_SELECT_ERROR)
		return (FT_SELECT_ERROR);

	set_terminal_size(select);
	tputs(select->cap.cap[CAP_VI], 1, ft_putc); // cursor invisible
	tputs(select->cap.cap[CAP_TI], 1, ft_putc);
	set_cursor(&(select->cap), 0, 0);
	set_footer(select, &(select->footer));
	return (FT_SELECT_SUCCESS);
}
