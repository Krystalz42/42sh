/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_environment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 04:07:03 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/03 04:07:12 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void 		remove_environment(char *string)
{
	char		**table;
	char		**cpy;
	int 		i;

	table = env_table(NULL, ENV_REC);
	cpy = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(table)));
	i = -1;
	if (table)
		while (table[++i])
			if (ft_strcmp(string, ft_strchr(table[i], '=')))
				cpy[i] = table[i];
	cpy[i] = NULL;
	ft_memdel((void **)&table);
	env_table(cpy, ENV_INIT);
}
