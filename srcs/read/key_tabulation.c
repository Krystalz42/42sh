/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tabulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:39:56 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 14:05:43 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			key_tab(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		(*read_std)->completion++;
		continue_completion(read_std);
	}
	else
	{
		init_completion(read_std);
	}
	return (1);
}
