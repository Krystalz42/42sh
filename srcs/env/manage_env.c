/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 04:25:19 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/04 21:01:52 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char				**builtin_env(char **command)
{
	int				index;
	int				option;
	int				t;

	t = 0;
	option = 0;
	while (command[++t] && command[t][0] == '-')
	{
		index = -1;
		while (command[t][++index])
			if (command[t][index] == 'u' || command[t][index] == 'i')
				option = command[t][index];

	}
	if (option == 'i')
		return (start_from_null(command + t));
	else if (option == 'u')
		return (start_from_less(command + t));
	else
		return (start_from_full(command + t));
}