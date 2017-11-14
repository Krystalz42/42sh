/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:37:30 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/14 14:37:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		**ft_arraysub(char **argv, size_t start, size_t length)
{
	size_t		index;
	char		**new;

	new = NULL;
	if (argv && length > 0)
	{
		index = 0;
		new = (char **)ft_memalloc(sizeof(char *) * (length + 1));
		while (length--)
			new[index++] = ft_strdup(argv[start++]);
	}
	return (new);
}

size_t			ft_arraylen(char **argv)
{
	size_t		index;

	index = 0;
	while (argv[index])
		index++;
	return (index);
}

char			**ft_arrayjoin(char **a1, char **a2)
{
	size_t		index;
	size_t		i;
	char		**new;

	new = NULL;
	if (!a1 && a2)
		return (ft_arraysub(a2, 0, ft_arraylen(a2)));
	if (!a2 && a1)
		return (ft_arraysub(a1, 0, ft_arraylen(a1)));
	if (!a1 && !a2)
		return (NULL);
	index = 0;
	i = 0;
	new = (char**)ft_memalloc(sizeof(char*) * (ft_arraylen(a1) + ft_arraylen(a2) + 1));
	while (a1[i])
		new[index++] = ft_strdup(a1[i++]);
	i = 0;
	while (a2[i])
		new[index++] = ft_strdup(a2[i++]);
	new[index] = NULL;
	return (new);
}
