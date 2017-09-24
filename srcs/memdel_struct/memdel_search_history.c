/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel_search_history.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:16:24 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 20:03:51 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			memdel_lfh(t_lfh **hist_search)
{
	if ((*hist_search))
	{
		memdel_cmd(&((*hist_search)->cmd));
		ft_memdel((void **)hist_search);
	}
	return (1);
}
