/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/10/28 17:02:08 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static unsigned int	which_len(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
	{
		if (str[len] == '=')
			break ;
		len++;
	}
	return (len);
}

// Only delete with an = sign at the end
uint8_t				ft_unsetenv(t_node *node, int info)
{
	unsigned int	i;
	unsigned int	len;
	char			**env;

	(void)info;
	env = node->content->env_option ? node->content->env : env_table(NULL, ENV_REC);
	i = 0;
	if (tablen(node->content->command) == 1 || node->content->command[1][0] == 0 ||
		search_char(node->content->command[1], '=') > 1)
			return (var_return(ft_error("usage: ", "unsetenv VAR", 1)));
	len = which_len(node->content->command[1]);
	ft_putchar(node->content->command[1][len]);
	while (env[i])
	{
		if (!ft_strncmp(env[i], node->content->command[1], len) &&
			(!env[i][len] || (env[i][len] && env[i][len] == '=')))
			break ;
		i++;
	}
	if (env[i])
	{
		ft_putendl("Success.");
		remove_environment(node->content->command[1]);
	}
	else
		return (var_return(ft_error(node->content->command[1], " not found.", 1)));
	return (var_return(0));
}
