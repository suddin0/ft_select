#ifndef FT_SELECT_DEFINES_H
# define FT_SELECT_DEFINES_H

/**
* The following define is used with the function `tgetent`. This function
* require the first parameter to either be a buffer (of enough length) or NULL
* depending in the library version. GNU termcap do not require any buffer as
* it store datas internally
**/

# ifdef unix
#  define IS_UNIX					1
#  define TERMCAP_BUFF_SIZE			2048
# else
#  define IS_UNIX					0
#  define TERMCAP_BUFF_SIZE			0
# endif

# ifdef linux
#  define IS_LINUX					1
# else
#  define IS_LINUX					0
# endif

# if !defined(FALSE)
#  define FALSE						0
# endif

# if !defined(TRUE)
#  define TRUE						1
# endif

#define MAX_LONGOPT					2
#define MAX_SHORTOPT				10

/**
* The following defines are used to to represent the size of the key tables
* That will contain function pointers.
*
* The KEY SEQ numbers are determined by how many different keysequences are
* managed (which can be found in `keys.h`).
**/

# define MAX_KEY_SEQ_TABLE_LEN		15
# define MAX_KEY_TABLE_LEN			15

/**
* The following define is used throughout out entire program to represent a
* success or error of a routine.
**/

#define FT_SELECT_ERROR				-1
#define FT_SELECT_SUCCESS			0

/**
* The following define is used to store user input data. It is supposed to
* store a single event at a time for example a simpel key press, or special keys
* such as home button, or right arrow key that create a sequence of data instead
* of a simpel char.
*
* The value 32 is supposed to be enough as most of the sequences do not surpass
* 20 bytes.
**/

#define READ_DATA_SIZE				32

/**
* The following define is used throughout out entire program to display data to
* the user and to get user unput from.
*/

# define SELECT_DATA_FD				FT_STDIN_FD


# define VISUAL_OUT_OF_BOUND		-1
# define INDEX_OUT_OF_BOUND			-2

# define VISUAL_DATA_SPACING		1


# define FOOTER_HEIGHT				1

/**
* defines used to control `print_data`
**/

# define POPT_NO_OPT				0b00000000
# define POPT_REVERSE				0b00000001
# define POPT_COLOR					0b00000010
// # define POPT_HIGHLIGHT				0b00000100
// # define POPT_HIGHLIGHT				0b00001000
// # define POPT_HIGHLIGHT				0b00010000
// # define POPT_HIGHLIGHT				0b00100000
// # define POPT_HIGHLIGHT				0b01000000
// # define POPT_HIGHLIGHT				0b10000000


/**
* Capacity related
**/

# define CAP_MAX_CAHR_SIZE		3
# define DESC_MAX_CAHR_SIZE		256

# define CAP_CM					0
# define CAP_TI					1
# define CAP_VI					2
# define CAP_TE					3
# define CAP_VE					4
# define CAP_CL					5
# define CAP_CD					6
# define CAP_MR					7
# define CAP_ME					8
# define CAP_US					9
# define CAP_SO					10
# define CAP_DELETE_N_LINE		11
# define CAP_DELETE_LINE		12
# define CAP_KEY_UP				13
# define CAP_KEY_DOWM			14
# define CAP_KEY_LEFT			15
# define CAP_KEY_RIGHT			16
# define CAP_KEY_DELETE			17
# define CAP_KEY_PAGE_UP		18
# define CAP_KEY_PAGE_DOWN		19
# define CAP_KEY_HOME			20
# define CAP_KEY_END			21
# define CAP_KEY_TAB_LEFT		22
# define CAP_KEY_SCROLL_UP		23
# define CAP_KEY_SCROLL_DOWN	24
# define CAP_MAX_SIZE			25

# define DESC_CM				"Position the cursor at line l, column c."
# define DESC_TI				"Put the terminal into whatever special mode."
# define DESC_VI				"Makes the cursor invisible."
# define DESC_TE				"Undo what is done by the `ti' string."
# define DESC_VE				"Return the cursor to normal."
# define DESC_CL 				"Clears the entire screen."
# define DESC_CD				"Clear the line the cursor is on."
# define DESC_MR				"Enter reverse-video mode."
# define DESC_ME				"Turns off all appearance modes."
# define DESC_US				"Turn on underline mode."
# define DESC_SO				"Enter standout mode."
# define DESC_DELETE_N_LINE		"Delete n lines starting from cursor position line."
# define DESC_DELETE_LINE		"Delete the lien where the cursor is."
# define DESC_KEY_UP			"Input characters sent by typing the up-arrow key."
# define DESC_KEY_DOWM			"Input characters sent by typing the down-arrow key."
# define DESC_KEY_LEFT			"Input characters sent by typing the left-arrow key."
# define DESC_KEY_RIGHT			"Input characters sent by typing the right-arrow key."
# define DESC_KEY_DELETE		"Input characters sent by the `delete character` key."
# define DESC_KEY_PAGE_UP		"Input characters sent by the `previous page` key."
# define DESC_KEY_PAGE_DOWN		"Input sent by the `next page` key."
# define DESC_KEY_HOME			"Input characters sent by the `home down` key"
# define DESC_KEY_END			"XXX"
# define DESC_KEY_TAB_LEFT		"XXX"
# define DESC_KEY_SCROLL_UP		"XXX"
# define DESC_KEY_SCROLL_DOWN	"XXX"


#endif
