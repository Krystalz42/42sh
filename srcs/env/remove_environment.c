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
	size_t		len;
	int 		i;

	table = env_table(NULL, ENV_REC);
	len = ft_tablen(table);
	cpy = (char **)ft_memalloc(sizeof(char *) * (len));
	i = -1;
	while (table[++i])
		if (!compare_environment(string, table[i]))
		{
			cpy[i] = table[i];
			STR_FD(table[i], g_fdb);
			CHAR_FD(10, g_fdb);
		}
	cpy[i] = NULL;
	ft_memdel((void **)&table);
	env_table(cpy, ENV_INIT);
}
