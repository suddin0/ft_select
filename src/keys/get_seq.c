#include "ft_select.h"

static inline int check_sek(char *data, char *cap, char *ansi)
{
	if(cap)
	{
		if(ft_strcmp(data, cap) == 0)
			return (TRUE);
	}
	if(ft_strcmp(data, ansi) == 0)
		return (TRUE);
	return (FALSE);
}

int get_seq(t_cap cap, char *data)
{
	if(check_sek(data, cap.key_up, ANSI_UP))
		return (SEQ_KEY_UP);
	else if(check_sek(data, cap.key_dowm, ANSI_DOWN))
		return (SEQ_KEY_DOWN);
	else if(check_sek(data, cap.key_left, ANSI_LEFT))
		return (SEQ_KEY_LEFT);
	else if(check_sek(data, cap.key_right, ANSI_RIGHT))
		return (SEQ_KEY_RIGHT);
	else if(check_sek(data, cap.key_delete, ANSI_DELETE))
		return (SEQ_KEY_DELETE);
	else if(check_sek(data, cap.key_page_up, ANSI_PUP))
		return (SEQ_KEY_PAGE_UP);
	else if(check_sek(data, cap.key_page_down, ANSI_PDOWN))
		return (SEQ_KEY_PAGE_DOWN);
	else if(check_sek(data, cap.key_home, ANSI_HOME))
		return (SEQ_KEY_HOME);
	else if(check_sek(data, cap.key_end, ANSI_END))
		return (SEQ_KEY_END);
	else if(check_sek(data, cap.key_tab_left, ANSI_TLEFT))
		return (SEQ_KEY_TAB_LEFT);
	else if(check_sek(data, cap.key_scroll_up, ANSI_SUP))
		return (SEQ_SCROLL_UP);
	else if(check_sek(data, cap.key_scroll_down, ANSI_SDWN))
		return (SEQ_SCROLL_DOWN);
	return (SEQ_UNKNOWN);
}
