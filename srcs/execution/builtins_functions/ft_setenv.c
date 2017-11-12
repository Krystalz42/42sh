/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/10/28 17:05:12 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static unsigned int		search_pos_char(const char *str, char c)
{
	int					i;

	i = -1;
	while (str[++i])
		if (str[i] == c)
			break ;
	return ((unsigned int)i);
}

unsigned int			search_char(char *str, char c)
{
	unsigned int		match;
	unsigned int		i;

	i = 0;
	match = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (i == 0)
			{
				return (match);
			}
			match++;
		}
		i++;
	}
	return (match);
}

static char				*ft_strndup(const char *src, unsigned int len)
{
	char				*res;
	unsigned int		i;

	i = 0;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (src[i] && i != len)
	{
		res[i] = src[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

static int				check_setenv(char **command)
{
	if (tablen(command) == 1 || command[1][0] == 0 ||
		search_char(command[1], '=') != 1)
		{
			ft_error("usage:", " setenv VAR=value", 0);
			return (1);
		}
	return (0);
}

uint8_t					ft_setenv(t_node *node, int info)
{
	char				*variable;
	unsigned int		len;
	unsigned int		i;
	char				**env;

	(void)info;
	env = node->content->env_option ? node->content->env : env_table(NULL, ENV_REC);
	i = 0;
	if (check_setenv(node->content->command) == 1)
		return (var_return(1));
	len = search_pos_char(node->content->command[1], '=');
	variable = ft_strndup(node->content->command[1], search_pos_char(node->content->command[1], '='));
	while (env[i])
	{
		if (!ft_strncmp(env[i], node->content->command[1], len))
		{
			ft_error(variable, " is already set.", 0);
			free(variable);
			return (var_return(1));
		}
		i++;
	}
	add_environment(node->content->command[1]);
	free(variable);
	return (var_return(0));
}
