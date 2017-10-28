/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 20:10:36 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/25 20:10:37 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmd			*keep_buffer(t_cmd *cmd, int flags)
{
	static t_cmd *save;

	if (flags)
		save = NULL;
	else if (cmd)
		save = cmd;
	return (save);
}