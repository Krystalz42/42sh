/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 04:25:19 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/03 04:25:22 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char				**manage_option(char *string)
{
	char		**table;

	table = env_table(NULL, ENV_REC);
	if (string)
	{

	}
	return (usage())
}


char				**manage_env(char *flag, char *str)
{
	int 		opt;

	opt = 0;
	if (flag && *flag == '-')
	{
		while (*flag++)
			if (*flag == 'i' || *flag == 'u')
				opt = *flag;
		return ((opt == u) ? manage_option(str) : NULL);
	}
	return (table);
}