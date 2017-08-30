/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyCmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/27 18:04:14 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/27 18:04:32 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			copyCmd(t_read **readStd, t_cmd *cpy)
{
	t_cmd		*cmd;

	cmd = NULL;
	(*readStd)->cmd = cmd;
	(*readStd)->cmd = createElement('\0');
	cpy = firstCmd(cpy, 1);
	while (cpy->c)
	{
		keyPrint(readStd, cpy->c);
		cpy = cpy->next;
	}
}
