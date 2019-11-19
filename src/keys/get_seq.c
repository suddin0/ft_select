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
	if(check_sek(data, cap.cap[CAP_KEY_UP], ANSI_UP))
		return (SEQ_KEY_UP);
	else if(check_sek(data, cap.cap[CAP_KEY_DOWM], ANSI_DOWN))
		return (SEQ_KEY_DOWN);
	else if(check_sek(data, cap.cap[CAP_KEY_LEFT], ANSI_LEFT))
		return (SEQ_KEY_LEFT);
	else if(check_sek(data, cap.cap[CAP_KEY_RIGHT], ANSI_RIGHT))
		return (SEQ_KEY_RIGHT);
	else if(check_sek(data, cap.cap[CAP_KEY_DELETE], ANSI_DELETE))
		return (SEQ_KEY_DELETE);
	else if(check_sek(data, cap.cap[CAP_KEY_PAGE_UP], ANSI_PUP))
		return (SEQ_KEY_PAGE_UP);
	else if(check_sek(data, cap.cap[CAP_KEY_PAGE_DOWN], ANSI_PDOWN))
		return (SEQ_KEY_PAGE_DOWN);
	else if(check_sek(data, cap.cap[CAP_KEY_HOME], ANSI_HOME))
		return (SEQ_KEY_HOME);
	else if(check_sek(data, cap.cap[CAP_KEY_END], ANSI_END))
		return (SEQ_KEY_END);
	else if(check_sek(data, cap.cap[CAP_KEY_TAB_LEFT], ANSI_TLEFT))
		return (SEQ_KEY_TAB_LEFT);
	else if(check_sek(data, cap.cap[CAP_KEY_SCROLL_UP], ANSI_SUP))
		return (SEQ_SCROLL_UP);
	else if(check_sek(data, cap.cap[CAP_KEY_SCROLL_DOWN], ANSI_SDWN))
		return (SEQ_SCROLL_DOWN);
	return (SEQ_UNKNOWN);
}
