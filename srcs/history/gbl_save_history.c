/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gbl_save_history.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:51:12 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 19:56:57 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_hist		*gbl_save_history(t_hist *hist, int flags)
{
	static t_hist		*save;

	if (!flags)
		save = NULL;
	else if (hist)
		save = hist;
	return (save);
}
