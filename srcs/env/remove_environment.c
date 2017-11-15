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

void		remove_environment(char *string)
{
	char		**table;
	char		**cpy;
	int			i;
	int			c;

	table = env_table(NULL, ENV_REC);
	cpy = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(table)));
	c = 0;
	i = 0;
	while (table[i])
	{
		if (compare_environment(string, table[i]))
			free(table[i]);
		else
		{
			cpy[c] = table[i];
			c++;
		}
		i++;
	}
	cpy[c] = NULL;
	ft_memdel((void **)&table);
	env_table(cpy, ENV_INIT);
}
