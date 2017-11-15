
#include <sh.h>

uint8_t					builtin_setenv(t_node *node, int inf __attribute__((unused)))
{
	if (ft_strchr(node->content->command[1], '=') &&
			node->content->command[1][0] != '=')
	{
		if (my_getenv(node->content->command[1]))
		{
			remove_environment(node->content->command[1]);
			add_environment(node->content->command[1]);
		}
		else
		{
			add_environment(node->content->command[1]);
		}
		return (var_return(0));
	}
	else
	{
		error_msg(SETENV, WRONG_FORMAT, node->content->command[1]);
		usage_setenv();
		return (var_return(1));
	}
}
