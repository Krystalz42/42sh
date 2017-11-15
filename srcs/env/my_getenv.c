/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:48:59 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/15 17:27:24 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

size_t				compare_environment(const char *s1, const char *s2)
{
	size_t		length;

	length = 0;
	while (s1 && s2 && s1[length] && s2[length] && s1[length] == s2[length])
	{
		if (s2[length + 1] == '=')
			return (length);
		length++;
	}
	return (0);
}

/*
*************** PUBLIC *********************************************************
*/

char			*my_getenv(char *name)
{
	int		index;
	char	**environ;

	index = -1;
	environ = env_table(NULL, ENV_REC);
	while (environ && environ[++index])
		if (compare_environment(name, environ[index]))
			return (ft_strchr(environ[index], '=') + 1);
	return (NULL);
}
