#include "ft_select.h"

static int init_termios(t_select *select)
{
	if(!isatty(FT_STDIN_FD))
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : The input filedescriptor is not a terminal.\n");
		return (FT_SELECT_ERROR);
	}

	if(tcgetattr(FT_STDIN_FD, &(select->termios_setup)) || tcgetattr(FT_STDIN_FD, &(select->termios_backup)))
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error : unable to get terminal informations (termios) : %s.\n", strerror(errno));
		return (FT_SELECT_ERROR);
	}
	return (FT_SELECT_SUCCESS);
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
	return (FT_SELECT_SUCCESS);
}
