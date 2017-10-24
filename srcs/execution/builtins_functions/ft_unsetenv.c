/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/10/24 15:38:20 by sbelazou         ###   ########.fr       */
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

uint8_t				ft_unsetenv(char **command, char **env)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	if (tablen(command) == 1 || command[1][0] == 0 ||
		search_char(command[1], '=') > 1)
		RETVAR(ft_error("usage: ", "unsetenv VAR", 1));
	len = which_len(command[1]);
	ft_putchar(command[1][len]);
	while (env[i])
	{
		if (!ft_strncmp(env[i], command[1], len) &&
			(!env[i][len] || (env[i][len] && env[i][len] == '=')))
			break ;
		i++;
	}
	if (env[i])
		ft_putendl("SUCCESS");
		//remove_environment(command[1]);
	else
		RETVAR(ft_error(command[1], " not found.", 1));
	RETVAR(0);
}
