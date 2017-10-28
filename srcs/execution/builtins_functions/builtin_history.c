//
// Created by Alexandre ROULIN on 10/12/17.
//

#include <sh.h>

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
	log_trace("%s, %d", *command, option);
	if (option == 'c')
		return (b_clear_history());
	else if (option == 'd')
		return (b_delete_history_offset(ft_atoi(*command)));
	else if (option == 'w')
		return (b_write_history_in_file(*command ? ft_strdup(*command) :
								get_str_from_history()));
	else if (option == 'r')
		return (write_history_in_sh(*command ? ft_strdup(*command) :
									  get_str_from_history()));
	else
		return (b_write_history());
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
	while (command[index] && command[index][0] == '-')
	{
		if (!ft_strcmp("--help", command[1]))
			return (var_return(usage_history()));
		c = 0;
		while (command[index][c])
		{
			ret = check_option_history(command[index][c]);
			if (ret == 1)
				option = command[index][c];
			else if (ret == -1)
				return (var_return(error_builtin(HISTORY, OPTION_NO_FOUND, command[index] + 1)));
			c++;
		}
		index++;
	}
	return (looking_for_fct(command + index, option));
}