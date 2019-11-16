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
	// select->termios_setup.c_lflag =  ~(ICANON | ECHO);
	select->termios_setup.c_lflag =  ~(ECHO);
	// select->termios_setup.c_cc[VMIN] = 1;
	// select->termios_setup.c_cc[VTIME] = 0;
	if(tcsetattr(select->data_fd, TCSANOW, &select->termios_setup))
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : %s\n", ERR_TERMSETTING);
		return (FT_SELECT_ERROR);
	}
	return (FT_SELECT_SUCCESS);
}


static inline void init_cap(t_cap *cap)
{
	cap->cm	= 				tgetstr("cm", NULL);
	cap->ti	= 				tgetstr("ti", NULL);
	cap->te	= 				tgetstr("ti", NULL);
	cap->vi	=				tgetstr("vi", NULL);
	cap->ve	=				tgetstr("ve", NULL);
	cap->cl	=				tgetstr("cl", NULL);
	cap->cd	=				tgetstr("cd", NULL);
	cap->mr	=				tgetstr("mr", NULL);
	cap->me =				tgetstr("me", NULL);
	cap->key_left =			tgetstr("kl", NULL);
	cap->key_right =		tgetstr("kr", NULL);
	cap->key_up =			tgetstr("ku", NULL);
	cap->key_dowm =			tgetstr("kd", NULL);
	cap->key_delete =		tgetstr("kD", NULL);
	cap->key_page_up =		tgetstr("kP", NULL); /* A verifier */
	cap->key_page_down =	tgetstr("kN", NULL); /* A verifier */
	cap->key_home =			tgetstr("kH", NULL);
	cap->key_tab_left =		tgetstr("XX", NULL);
	cap->key_scroll_up =	tgetstr("XX", NULL);
	cap->key_scroll_down =	tgetstr("XX", NULL);
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
	init_cap(&(select->cap));
	return (FT_SELECT_SUCCESS);
}

int init_term(t_select *select)
{
	if(init_termios(select) == FT_SELECT_ERROR)
		return (FT_SELECT_ERROR);
	if(init_termcap(select) == FT_SELECT_ERROR)
		return (FT_SELECT_ERROR);
	tputs(select->cap.vi, 1, ft_putc); // cursor invisible
	tputs(select->cap.ti, 1, ft_putc);
	set_terminal_size(select);
	set_cursor(&(select->cap), 0, 0);
	return (FT_SELECT_SUCCESS);
}
