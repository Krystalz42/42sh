/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 00:03:49 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/10 18:15:14 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		splitEnv(char *env)
{
	char		*name;
	char		*value;
	int			i;

	i = -1;
	while (env[++i] && env[i] != '=')
		;
	if (!(name = ft_strsub(env, 0, i)))
		return ;
	if (!(value = ft_strdup(env + i + 1)))
		return ;
	addListEnv(name, value);
}
