#include "ft_select.h"

void signal_test(int a)
{
	t_select *select;

	select = get_select();
	ft_dprintf(select->data_fd, "SIGNAL : %d            \n", a);
}

void sigwinch_handler(UNUSED int sig)
{
	// t_select *select;

	// select = get_select();
	// set_terminal_size(select);
	// show_all_data(select);
}

void signal_man()
{
	signal(SIGWINCH,	signal_test);
	signal(SIGABRT,		signal_test);
	signal(SIGINT,		signal_test);
	signal(SIGSTOP,		signal_test);
	signal(SIGCONT,		signal_test);
	signal(SIGTSTP,		signal_test);
	signal(SIGKILL,		signal_test);
	signal(SIGQUIT,		signal_test);
}
