/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_environment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 03:06:18 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/03 03:06:19 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		add_environment(char *string)
{
	char		**table;
	char		**cpy;
	size_t		len;
	int 		i;

	table = env_table(NULL, ENV_REC);
	len = ft_tablen(table);
	cpy = (char **)ft_memalloc(sizeof(char *) * (len + 2));
	i = -1;
	if (table)
		while (table[++i])
			cpy[i] = table[i];
	cpy[i] = ft_strdup(string);
	cpy[i + 1] = NULL;
	ft_memdel((void **)&table);
	env_table(cpy, ENV_INIT);
}