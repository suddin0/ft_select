#include "ft_select.h"

/**
* The goal of the following function is to get the terminal size (max char for
* each line AKA `colon` and maximum line AKA `tow` we can show in the current
* size).
* This function is used in multiple places. At first it is used to initiate
* the whole program and later each time the terminal is reset and the signal
* `SIGWINCH` is called (SIGWINCH is called when thet erminal emulator dimantion
* changes).
*
* In this function we set 4 elements of the structure `t_select` where `col` and
* `row` represent the Real size of the terminal and `virtual_col` and
* `virtual_row` represents a virtual area where thermianl will output data.
* we use a virtual area to write data so we can possibily show a `bottom bar`
* with extra informations.
*
* NOTE: The order of initialization must be rpeserved for the following
* Variables:
* - select->vdata.data_par_line
* - select->vdata.data_index
* - select->vdata.max_data_index
**/

void set_terminal_size(t_select *select)
{
	struct winsize w;

	ioctl(FT_STDIN_FD, TIOCGWINSZ, &w);
	select->vdata.row = w.ws_row;
	select->vdata.col = w.ws_col;

	select->vdata.virtual_col = select->vdata.col;
	select->vdata.virtual_row = select->vdata.row - 1;

	select->vdata.data_par_line = get_data_par_line(select);
	select->vdata.data_index = get_data_index(select);
	select->vdata.max_data_index = get_max_data_index(select);
}
