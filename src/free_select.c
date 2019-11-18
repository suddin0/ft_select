#include "ft_select.h"

void free_select(t_select *select)
{
	if(select->data_pack.data)
	{
		free(select->data_pack.data);
		select->data_pack.data = NULL;
	}
	if(select->data)
	{
		free(select->data);
		select->data = NULL;
	}
	if(select->data_fd != -1)
		close(select->data_fd);

	if(select->cap.cm)
		free(select->cap.cm);
	if(select->cap.ti)
		free(select->cap.ti);
	if(select->cap.vi)
		free(select->cap.vi);

	if(select->cap.te)
		free(select->cap.te);
	if(select->cap.ve)
		free(select->cap.ve);
	if(select->cap.cl)
		free(select->cap.cl);
	if(select->cap.cd)
		free(select->cap.cd);
	if(select->cap.mr)
		free(select->cap.mr);
	if(select->cap.me)
		free(select->cap.me);
	if(select->cap.us)
		free(select->cap.us);
	if(select->cap.so)
		free(select->cap.so);

	if(select->cap.key_up)
		free(select->cap.key_up);
	if(select->cap.key_dowm)
		free(select->cap.key_dowm);
	if(select->cap.key_left)
		free(select->cap.key_left);
	if(select->cap.key_right)
		free(select->cap.key_right);

	if(select->cap.key_delete)
		free(select->cap.key_delete);
	if(select->cap.key_page_up)
		free(select->cap.key_page_up);
	if(select->cap.key_page_down)
		free(select->cap.key_page_down);
	if(select->cap.key_home)
		free(select->cap.key_home);
	if(select->cap.key_end)
		free(select->cap.key_end);
	if(select->cap.key_tab_left)
		free(select->cap.key_tab_left);
	if(select->cap.key_scroll_up)
		free(select->cap.key_scroll_up);
	if(select->cap.key_scroll_down)
		free(select->cap.key_scroll_down);
}
