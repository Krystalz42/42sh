/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:52:17 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/20 11:26:47 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			memdel_cmd(t_cmd **cmd)
{
	t_cmd *tmp;

	while ((*cmd) && (*cmd)->prev)
		(*cmd) = (*cmd)->prev;
	while ((*cmd))
	{
		tmp = (*cmd);
		(*cmd) = (*cmd)->next;
		free(tmp);
	}
	(*cmd) = NULL;
	return (1);
}

int			memdel_read(t_read **read_std)
{
	memdel_cmd(&((*read_std)->cmd));
	memdel_completion(&((*read_std)->tab_));
	ft_memdel((void **)read_std);
	return (1);
}
