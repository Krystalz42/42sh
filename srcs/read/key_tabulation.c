/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_tabulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:39:56 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/17 21:27:10 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			key_tab(t_read **read_std)
{
	if ((*read_std)->completion)
	{
		continue_completion(read_std);
		(*read_std)->completion++;
	}
	else
	{
		init_completion(read_std);
		(*read_std)->completion = 2;
	}
	return (1);
}
