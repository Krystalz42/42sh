/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_environment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 03:06:18 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:13:29 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		add_environment(char *string)
{
	char		**table;
	char		**cpy;
	int			i;

	table = env_table(NULL, ENV_REC);
	cpy = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(table) + 2));
	i = -1;
	if (table)
		while (table[++i])
			cpy[i] = table[i];
	cpy[i] = ft_strdup(string);
	cpy[i + 1] = NULL;
	ft_memdel((void **)&table);
	env_table(cpy, ENV_INIT);
}
