#include "ft_select.h"

int loop(UNUSED t_select *select)
{
	int rd;
	char data[READ_DATA_SIZE];
	int loop_control;

	loop_control = TRUE;
	while(loop_control && (rd = read(select->data_fd, data, READ_DATA_SIZE)) > 0)
	{
		data[rd] = 0;
		if(rd > 1 && data[0] == KEY_ESC)
			escape_key_man(select, get_seq(select->cap, data), &loop_control);
		else if(rd == 1)
			key_man(select, data[0], &loop_control);
		else
		{
			ft_dprintf(SELECT_DATA_FD, "Strage keys---\n");
		}
	}

	if(rd < 0)
	{
		ft_dprintf(FT_STDERR_FD, "[-] Error: reading user input : %s.\n", strerror(errno));
		return (FT_SELECT_ERROR);
	}
	return (FT_SELECT_SUCCESS);
}
