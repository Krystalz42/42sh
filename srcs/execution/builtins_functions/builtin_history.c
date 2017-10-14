//
// Created by Alexandre ROULIN on 10/12/17.
//

#include <sh.h>


static uint8_t	help_history()
{
	ft_putstr_fd("-c            : Clear the history list.\n", STDERR_FILENO);
	ft_putstr_fd("-d offset     : Delete the history entry at     \
						position offset.\n", STDERR_FILENO);
	ft_putstr_fd("-a [pathname] : Append the new history lines to  \
						the history file.\n", STDERR_FILENO);
	ft_putstr_fd("-r [pathname] : Read the history file and append its \
						contents to the history list.\n", STDERR_FILENO);
	ft_putstr_fd("-w [pathname] : Write out the current history list \
						to the history file.\n", STDERR_FILENO);
	return ((uint8_t)0);
}

static uint8_t	usage_history(char c)
{
	ft_putstr_fd("history: option not found :-- ",STDERR_FILENO);
	ft_putchar_fd(c, STDERR_FILENO);
	ft_putchar_fd(10, STDERR_FILENO);
	help_history();
	return ((uint8_t)1);
}

static int		check_option_history(char c)
{
	static const char	potential[] = "rdawsc";
	int					index;

	index = 0;
	while (potential[index])
	{
		if (potential[index] == c)
			return (1);
		index++;
	}
	if (c == '-')
		return (0);
	return (-1);
}

uint8_t			looking_for_fct(char **command, int option)
{
	if (option)
	{
		if (option == 'c')
			return (b_clear_history());
		else if (option == 'd')
			return (b_delete_history_offset(ft_atoi(*command)));
		else if (option == 'a')
			return (b_write_history_in_file(*command ? ft_strdup(*command) :
									get_str_from_history()));
		else if (option == 'r')
			return (write_history_in_sh(ft_strdup(*command ? ft_strdup(*command) :
												  get_str_from_history())));
		else
			return (b_write_history());

	}
	return (usage_history((char)option));
}

uint8_t			builtin_history(char **command, char **env)
{
	int			option;
	int			index;
	int			c;
	int			ret;

	(void)env;
	option = 0;
	index = 1;
	while (command[index])
	{
		c = 0;
		if (command[index][c] == '-')
			while (command[index][c])
			{
				ret = check_option_history(command[index][c]);
				if (ret == 1)
					option = command[index][c];
				else if (ret == -1)
					return (var_return(usage_history(command[index][c])));
				c++;
			}
		index++;
	}
	return (looking_for_fct(command + index, option));
}