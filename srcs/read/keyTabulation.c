/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyTabulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/12 17:39:56 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/23 13:37:20 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			keyTab(t_read **readStd)
{
	if ((*readStd)->completion)
	{
		keyArrowRight(readStd);
	}
	else
	{
		initCompletion(readStd);
	}
	return (1);
}
