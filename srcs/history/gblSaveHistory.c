/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gblSaveHistory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:51:12 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/24 15:40:46 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_hist		*gblSaveHistory(t_hist *hist)
{
	static t_hist		*save;

	if (hist)
		save = hist;
	return (save);
}
