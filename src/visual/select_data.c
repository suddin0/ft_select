#include "ft_select.h"


void select_data(t_data_pack *pack)
{
	int index;
	int sel;

	if(pack->data_size <= 0)
		return ;

	index = index_of(pack, pack->cur_x, pack->cur_y);
	sel = pack->data[index]->selected;
	pack->data[index]->selected = (sel == TRUE) ? FALSE : TRUE;
	get_on(pack, pack->cur_x, pack->cur_y);
}
