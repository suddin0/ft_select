#ifndef KEYS_H
# define KEYS_H

/**
* All alphabetical and numeric values
**/

# define KEY_ZERO			'0'
# define KEY_ONE			'1'
# define KEY_TWO			'2'
# define KEY_THREE			'3'
# define KEY_FOUR			'4'
# define KEY_FIVE			'5'
# define KEY_SIZ			'6'
# define KEY_SEVEN			'7'
# define KEY_EIGHT			'8'
# define KEY_NINE			'9'

/**
* Lowercase letters
**/

# define KEY_A				'a'
# define KEY_B				'b'
# define KEY_C				'c'
# define KEY_D				'd'
# define KEY_E				'e'
# define KEY_F				'f'
# define KEY_G				'g'
# define KEY_H				'h'
# define KEY_I				'i'
# define KEY_J				'j'
# define KEY_K				'k'
# define KEY_L				'l'
# define KEY_M				'm'
# define KEY_N				'n'
# define KEY_O				'o'
# define KEY_P				'p'
# define KEY_Q				'q'
# define KEY_R				'r'
# define KEY_S				's'
# define KEY_T				't'
# define KEY_U				'u'
# define KEY_V				'v'
# define KEY_W				'w'
# define KEY_X				'x'
# define KEY_Y				'y'
# define KEY_Z				'z'

/**
* Uppercase letters
**/

# define KEY_SHIFT_A		'A'
# define KEY_SHIFT_B		'B'
# define KEY_SHIFT_C		'C'
# define KEY_SHIFT_D		'D'
# define KEY_SHIFT_E		'E'
# define KEY_SHIFT_F		'F'
# define KEY_SHIFT_G		'G'
# define KEY_SHIFT_H		'H'
# define KEY_SHIFT_I		'I'
# define KEY_SHIFT_J		'J'
# define KEY_SHIFT_K		'K'
# define KEY_SHIFT_L		'L'
# define KEY_SHIFT_M		'M'
# define KEY_SHIFT_N		'N'
# define KEY_SHIFT_O		'O'
# define KEY_SHIFT_P		'P'
# define KEY_SHIFT_Q		'Q'
# define KEY_SHIFT_R		'R'
# define KEY_SHIFT_S		'S'
# define KEY_SHIFT_T		'T'
# define KEY_SHIFT_U		'U'
# define KEY_SHIFT_V		'V'
# define KEY_SHIFT_W		'W'
# define KEY_SHIFT_X		'X'
# define KEY_SHIFT_Y		'Y'
# define KEY_SHIFT_Z		'Z'


# define KEY_ETX			0X03
# define KEY_EOT			0X04
# define KEY_BACK_SPACE		0X08
# define KEY_TAB			0X09
# define KEY_CRETURN		0X0D
# define KEY_ESC			0X1B
# define KEY_SPACEC			0X20
# define KEY_DELETE			0X7F

# define KEY_CTRL_C			KEY_ETX
# define KEY_CTRL_D			KEY_EOT
# define KEY_ENTER			KEY_CRETURN


/**
* Escape sequence definitions that is to be used with function pointer (jump
* tables).
**/

# define SEQ_KEY_UP 		0X00
# define SEQ_KEY_DOWN		0X01
# define SEQ_KEY_LEFT		0X02
# define SEQ_KEY_RIGHT		0X03
# define SEQ_KEY_DELETE		0X04
# define SEQ_KEY_PAGE_UP	0X05
# define SEQ_KEY_PAGE_DOWN	0X06
# define SEQ_KEY_HOME		0X07
# define SEQ_KEY_END		0X08
# define SEQ_KEY_TAB_LEFT	0X09
# define SEQ_SCROLL_UP		0X0A
# define SEQ_SCROLL_DOWN	0X0B

# define SEQ_UNKNOWN		0X0C

/**
* The followings are hardcoded ansi escape sequences. They are meant to be
* compared. with other string. They exists here bevause if for some reason the
* termcap database do not send the proper sequence at least we can use the
* folloing hardcoded seuquences to do the job.
**/

# define ANSI_SEQ_KEY_UP 		"\x1b\x5b\x41\0"
# define ANSI_SEQ_KEY_DOWN		"\x1b\x5b\x42\0"
# define ANSI_SEQ_KEY_LEFT		"\x1b\x5b\x44\0"
# define ANSI_SEQ_KEY_RIGHT		"\x1b\x5b\x43\0"
# define ANSI_SEQ_KEY_DELETE	"\x1b\x5b\x33\x7e\0"
# define ANSI_SEQ_KEY_PAGE_UP	"\x1b\x5b\x35\x7e\0"
# define ANSI_SEQ_KEY_PAGE_DOWN	"\x1b\x5b\x36\x7e\0"
# define ANSI_SEQ_KEY_HOME		"\x1b\x5b\x48\0"
# define ANSI_SEQ_KEY_END		"\x1b\x5b\x46\0"
# define ANSI_SEQ_KEY_TAB_LEFT	"\x1b\x5b\x5a\0"
# define ANSI_SEQ_SCROLL_UP		"\x1b[A\x1b[A\x1b[A\x1b[A\x1b[A\0"
# define ANSI_SEQ_SCROLL_DOWN	"\x1b[B\x1b[B\x1b[B\x1b[B\x1b[B\0"

/**
* The following aliases are created to save spaces in line (norm 42)
**/

# define ANSI_UP				ANSI_SEQ_KEY_UP
# define ANSI_DOWN				ANSI_SEQ_KEY_DOWN
# define ANSI_LEFT				ANSI_SEQ_KEY_LEFT
# define ANSI_RIGHT				ANSI_SEQ_KEY_RIGHT
# define ANSI_DELETE			ANSI_SEQ_KEY_DELETE
# define ANSI_PUP				ANSI_SEQ_KEY_PAGE_UP
# define ANSI_PDOWN				ANSI_SEQ_KEY_PAGE_DOWN
# define ANSI_HOME				ANSI_SEQ_KEY_HOME
# define ANSI_END				ANSI_SEQ_KEY_END
# define ANSI_TLEFT				ANSI_SEQ_KEY_TAB_LEFT
# define ANSI_SUP				ANSI_SEQ_SCROLL_UP
# define ANSI_SDWN				ANSI_SEQ_SCROLL_DOWN

/**
* The following defines are used to represent key table index
* The folloing defines represents the functionalities that is managed
* by the pressed keys.
**/

# define EXIT_KEY				0X00
# define LEFT_KEY				0X01
# define RIGHT_KEY				0X02
# define UP_KEY					0X03
# define DOWN_KEY				0X04
# define SELECT_KEY				0X05
# define ENTER_KEY				0X06
# define DELETE_KEY				0X07

#endif
