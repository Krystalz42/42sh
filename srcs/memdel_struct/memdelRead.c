/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdelRead.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 10:52:17 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/20 11:26:47 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			memdelCmd(t_cmd **cmd)
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

int			memdelRead(t_read **readStd)
{	
	memdelCmd(&((*readStd)->cmd));
	memdelCompletion(&((*readStd)->comp));
	ft_memdel((void **)readStd);
	return (1);
}
