#include "ft_select.h"


static inline void set_longopt(t_option *longopt, char *name, int has_arg, int val)
{
	longopt->name = name;
	longopt->has_arg = has_arg;
	longopt->flag = NULL;
	longopt->val = val;
}

static inline void set_longopt_list(t_option *longopt)
{
	set_longopt(&(longopt[0]), "someopt", NO_ARGUMENT, 'A');
	set_longopt(&(longopt[1]), "something", NO_ARGUMENT, 'B');
	set_longopt(&(longopt[2]), NULL, 0, 0);
}

static inline void set_opt(/* some option data holder, */ UNUSED int opt)
{
	/* compare and set your options here */
}


int arg_man(int argc, char **argv)
{
	t_getopt_arg	arg;
	t_option		longopt[MAX_LONGOPT + 1];
	char			shortopt[MAX_SHORTOPT + 1];
	int				opt;

	arg.argc = argc;
	arg.argv = argv;
	ft_strcpy(shortopt, "some data");
	set_longopt_list(longopt);

	while((opt = ft_getopt_long(arg, shortopt, longopt, NULL)) > -1)
	// while((opt = getopt_long(argc, argv, shortopt, (struct option *)longopt, NULL)) > -1)
	{
		if(opt == '?')
			return (FT_SELECT_ERROR);
		/* Set the option */
		set_opt(opt);
	}
	return(FT_SELECT_SUCCESS);
}
