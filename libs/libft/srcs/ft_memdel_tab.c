/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 20:33:56 by aroulin           #+#    #+#             */
/*   Updated: 2017/05/01 17:23:34 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include <stdio.h>

void	ft_memdel_tab(char **ta)
{
	int i;

	i = -1;
	if (!ta)
		return ;
	while (ta[++i])
		ft_strdel(&(ta[i]));
	ft_memdel((void **)&ta);
}
