#include "ft_select.h"

static int init_termios(t_select *select)
{
	if(!isatty(FT_STDIN_FD))
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : The input filedescriptor");
		ft_dprintf(FT_STDERR_FD, " is not a terminal.\n");
		return (FT_SELECT_ERROR);
	}

	if(tcgetattr(FT_STDIN_FD, &(select->termios_setup))\
		|| tcgetattr(FT_STDIN_FD, &(select->termios_backup)))
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : unable to get terminal infor");
		ft_dprintf(FT_STDERR_FD, "mations (termios) : %s.\n", strerror(errno));
		return (FT_SELECT_ERROR);
	}

	select->termios_setup.c_lflag =  ~(ICANON | ECHO);
	// select->termios_setup.c_lflag =  ~(ECHO);
	select->termios_setup.c_cc[VMIN] = 1;
	select->termios_setup.c_cc[VTIME] = 0;
	if(tcsetattr(STDERR_FILENO, TCSANOW, &select->termios_setup))
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : Unable to set terminal settings (termios).\n");
		return (FT_SELECT_ERROR);
	}
	return (FT_SELECT_SUCCESS);
}


void init_cap(t_cap *cap)
{
	cap->cm	= 				tgetstr("cm", NULL);
	cap->ti	= 				tgetstr("ti", NULL);
	cap->te	= 				tgetstr("ti", NULL);
	cap->vi	=				tgetstr("vi", NULL);
	cap->ve	=				tgetstr("ve", NULL);
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

int init_term(t_select *select)
{
	int success;

	if(init_termios(select) == FT_SELECT_ERROR)
		return (FT_SELECT_ERROR);
	select->term_name = getenv ("TERM");
	if(!select->term_name)
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : There is no envoronment variable called `TERM`.\n");
		ft_dprintf(FT_STDERR_FD, "Without this variable we can not initiate termcap.\n");
		return (FT_SELECT_ERROR);
	}

	if(IS_UNIX)
		success = tgetent (select->termcap_buff, select->term_name);
	else
		success = tgetent (NULL, select->term_name);
	if(success < 0)
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : Unable to acces the termcap database.\n");
		return (FT_SELECT_ERROR);

	}
	else if(success < 0)
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : no entry for the terminal type `%s`.\n", select->term_name);
		return (FT_SELECT_ERROR);
	}
	set_terminal_size(select);

	// tputs(tgetstr("ti", NULL), 1, ft_putc);
	tputs(select->cap.ti, 1, ft_putc);
	// tputs(select->cap.vi, 1, ft_putc); // cursor invisible
	return (FT_SELECT_SUCCESS);
}
