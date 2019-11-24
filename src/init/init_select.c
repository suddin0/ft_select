#include "ft_select.h"

static inline void set_select_to_zero(t_select *select)
{
	int i;

	i = 0;
	select->term_name = NULL;
	select->data_fd = -1;
	if(IS_UNIX)
		ft_memset(select->termcap_buff, 0, TERMCAP_BUFF_SIZE);

	select->argv_start_index = 0;
	select->data_size = 0;
	select->data = NULL;
	select->max_str_len = 0;

	ft_memset(&(select->data_pack), 0, sizeof(t_data_pack));
	ft_memset(&(select->cap), 0, sizeof(t_cap));
	ft_memset(&(select->footer), 0, sizeof(t_footer));
	while(i < CAP_MAX_SIZE)
	{
		select->cap.cap[i] = NULL;
		i++;
	}
}

void set_cap_name(t_cap *cap)
{
	ft_strcpy(cap->name[CAP_CM],					"cm");
	ft_strcpy(cap->name[CAP_TI],					"ti");
	ft_strcpy(cap->name[CAP_VI],					"vi");
	ft_strcpy(cap->name[CAP_TE],					"te");
	ft_strcpy(cap->name[CAP_VE],					"ve");
	ft_strcpy(cap->name[CAP_CL],					"cl");
	ft_strcpy(cap->name[CAP_CD],					"cd");
	ft_strcpy(cap->name[CAP_MR],					"mr");
	ft_strcpy(cap->name[CAP_ME],					"me");
	ft_strcpy(cap->name[CAP_US],					"us");
	ft_strcpy(cap->name[CAP_SO],					"so");
	ft_strcpy(cap->name[CAP_DL],					"DL");
	ft_strcpy(cap->name[CAP_AL],					"AL");
	ft_strcpy(cap->name[CAP_DELETE_LINE],			"dl");
	ft_strcpy(cap->name[CAP_KEY_UP],				"ku");
	ft_strcpy(cap->name[CAP_KEY_DOWM],				"kd");
	ft_strcpy(cap->name[CAP_KEY_LEFT],				"kl");
	ft_strcpy(cap->name[CAP_KEY_RIGHT],				"kr");
	ft_strcpy(cap->name[CAP_KEY_DELETE],			"kD");
	ft_strcpy(cap->name[CAP_KEY_PAGE_UP],			"kP");
	ft_strcpy(cap->name[CAP_KEY_PAGE_DOWN],			"kN");
	ft_strcpy(cap->name[CAP_KEY_HOME],				"kH");
	ft_strcpy(cap->name[CAP_KEY_END],				"XX");
	ft_strcpy(cap->name[CAP_KEY_TAB_LEFT],			"XX");
	ft_strcpy(cap->name[CAP_KEY_SCROLL_UP],			"XX");
	ft_strcpy(cap->name[CAP_KEY_SCROLL_DOWN],		"XX");
}

void set_cap_desc(t_cap *cap)
{
	ft_strcpy(cap->desc[CAP_CM],					DESC_CM);
	ft_strcpy(cap->desc[CAP_TI],					DESC_TI);
	ft_strcpy(cap->desc[CAP_VI],					DESC_VI);
	ft_strcpy(cap->desc[CAP_TE],					DESC_TE);
	ft_strcpy(cap->desc[CAP_VE],					DESC_VE);
	ft_strcpy(cap->desc[CAP_CL],					DESC_CL);
	ft_strcpy(cap->desc[CAP_CD],					DESC_CD);
	ft_strcpy(cap->desc[CAP_MR],					DESC_MR);
	ft_strcpy(cap->desc[CAP_ME],					DESC_ME);
	ft_strcpy(cap->desc[CAP_US],					DESC_US);
	ft_strcpy(cap->desc[CAP_SO],					DESC_SO);
	ft_strcpy(cap->desc[CAP_DL],					DESC_DL);
	ft_strcpy(cap->desc[CAP_AL],					DESC_AL);
	ft_strcpy(cap->desc[CAP_DELETE_LINE],			DESC_DELETE_LINE);
	ft_strcpy(cap->desc[CAP_KEY_UP],				DESC_KEY_UP);
	ft_strcpy(cap->desc[CAP_KEY_DOWM],				DESC_KEY_DOWM);
	ft_strcpy(cap->desc[CAP_KEY_LEFT],				DESC_KEY_LEFT);
	ft_strcpy(cap->desc[CAP_KEY_RIGHT],				DESC_KEY_RIGHT);
	ft_strcpy(cap->desc[CAP_KEY_DELETE],			DESC_KEY_DELETE);
	ft_strcpy(cap->desc[CAP_KEY_PAGE_UP],			DESC_KEY_PAGE_UP);
	ft_strcpy(cap->desc[CAP_KEY_PAGE_DOWN],			DESC_KEY_PAGE_DOWN);
	ft_strcpy(cap->desc[CAP_KEY_HOME],				DESC_KEY_HOME);
	ft_strcpy(cap->desc[CAP_KEY_END],				DESC_KEY_END);
	ft_strcpy(cap->desc[CAP_KEY_TAB_LEFT],			DESC_KEY_TAB_LEFT);
	ft_strcpy(cap->desc[CAP_KEY_SCROLL_UP],			DESC_KEY_SCROLL_UP);
	ft_strcpy(cap->desc[CAP_KEY_SCROLL_DOWN],		DESC_KEY_SCROLL_DOWN);
}

void set_cap_mand(t_cap *cap)
{
	cap->mand[CAP_CM]				= TRUE;
	cap->mand[CAP_TI]				= FALSE;
	cap->mand[CAP_VI]				= FALSE;
	cap->mand[CAP_TE]				= FALSE;
	cap->mand[CAP_VE]				= FALSE;
	cap->mand[CAP_CL]				= FALSE;
	cap->mand[CAP_CD]				= FALSE;
	cap->mand[CAP_MR]				= FALSE;
	cap->mand[CAP_ME]				= FALSE;
	cap->mand[CAP_US]				= FALSE;
	cap->mand[CAP_SO]				= FALSE;
	cap->mand[CAP_DL]				= TRUE;
	cap->mand[CAP_AL]				= TRUE;
	cap->mand[CAP_DELETE_LINE]		= TRUE;
	cap->mand[CAP_KEY_UP]			= FALSE;
	cap->mand[CAP_KEY_DOWM]			= FALSE;
	cap->mand[CAP_KEY_LEFT]			= FALSE;
	cap->mand[CAP_KEY_RIGHT]		= FALSE;
	cap->mand[CAP_KEY_DELETE]		= FALSE;
	cap->mand[CAP_KEY_PAGE_UP]		= FALSE;
	cap->mand[CAP_KEY_PAGE_DOWN]	= FALSE;
	cap->mand[CAP_KEY_HOME]			= FALSE;
	cap->mand[CAP_KEY_END]			= FALSE;
	cap->mand[CAP_KEY_TAB_LEFT]		= FALSE;
	cap->mand[CAP_KEY_SCROLL_UP]	= FALSE;
	cap->mand[CAP_KEY_SCROLL_DOWN]	= FALSE;
}


int init_select(t_select *select)
{
	set_select_to_zero(select);
	if(get_terminal_fd(select) == FT_SELECT_ERROR)
		return (FT_SELECT_ERROR);

	set_cap_name(&(select->cap));
	set_cap_mand(&(select->cap));
	set_cap_desc(&(select->cap));

	signal_man();
	key_seq_table_init(select);
	return (FT_SELECT_SUCCESS);
}
