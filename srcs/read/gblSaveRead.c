/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gblSaveRead.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 15:31:38 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/27 17:46:00 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmd		*gblSaveRead(t_cmd *readStd)
{
	static t_cmd		*save;

	if (readStd)
		save = readStd;
	return (save);
}
