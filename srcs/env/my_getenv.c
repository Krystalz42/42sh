/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 02:48:59 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/03 02:49:01 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

size_t				compare_environment(char *s1, char *s2)
{
	size_t		len;

	len = 0;
	while (s1 && s2 && *s1 && *s2 && *s1 == *s2)
	{
		if (*s2 == '=')
			return (len);
		s1++;
		s2++;
		len++;
	}
	return (0);
}

char				*my_getenv(char *name)
{
	char	**environ;
	int 	i;

	i = -1;
	environ = env_table(NULL, ENV_REC);
	if (environ)
		while (environ[++i])
			if (compare_environment(name, environ[i]))
				return (ft_strchr(environ[i], '=') + 1);
	return (NULL);
}
