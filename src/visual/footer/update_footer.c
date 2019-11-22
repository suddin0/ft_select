#include "ft_select.h"

#define UNSET_ATTR			"\e[0m"
#define NORMAL_ATTR			"\e[8m"
#define BOLD_ATTR			"\e[1m"

#define BG_ATTR_START		"\e[30;48;5;"
#define FG_ATTR_START		"\e[38;5;"
#define ATTR_END			"m"


#define WHITE				"7"
#define BLACK				"235"
#define BLUE				"4"
#define YELLOW				"3"
#define NONE				"0"

#define BG_BLACK			BG_ATTR_START BLACK ATTR_END
#define BG_BLUE				BG_ATTR_START BLUE ATTR_END
#define BG_YELLOW			BG_ATTR_START YELLOW ATTR_END
#define BG_NONE				BG_ATTR_START NONE ATTR_END

#define FG_WHITE			FG_ATTR_START WHITE ATTR_END
#define FG_BLACK			FG_ATTR_START BLACK ATTR_END
#define FG_BLUE				FG_ATTR_START BLUE ATTR_END
#define FG_YELLOW			FG_ATTR_START YELLOW ATTR_END


void print_flesh(t_select *select, UNUSED char *fg, char *bg)
{

	ft_dprintf(select->data_fd, UNSET_ATTR BOLD_ATTR "%s%s\ue0b0" UNSET_ATTR,
		bg,
		fg,
		select->data_size
	);
}

void print_info(t_select *select, char *info, int val, char *fg, char *bg, char *bg_fg, char *next_bg)
{
	ft_dprintf(select->data_fd, "%s%s %s :%d " UNSET_ATTR , bg, fg, info, val);
	print_flesh(select, bg_fg, next_bg);
}


void update_footer(t_select *select)
{
	if(select->footer.active == FALSE)
		return ;
	set_cursor(&(select->cap), 0, select->vdata.virtual_row);

	print_info(select, "total data", select->data_size, 	FG_WHITE, BG_BLACK, FG_BLACK, BG_BLUE);
	print_info(select, "selected data", 0, 					FG_BLACK, BG_BLUE, FG_BLUE, BG_YELLOW);
	print_info(select, "visible data", select->data_size, 	FG_BLACK, BG_YELLOW, FG_YELLOW, BG_NONE);

}
/*

Total data :
qselected data :
deleted data :

line, X
TOP,BOT,All XX%

*/
// \e[30;48;5;90m
