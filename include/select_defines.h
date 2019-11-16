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


#endif
