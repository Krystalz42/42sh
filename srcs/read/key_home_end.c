/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   home_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 06:30:22 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/11 06:31:25 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			home_key(t_read **read_std)
{
	STR("HOME\n");
	(void)read_std;
	return (1);
}
int			end_key(t_read **read_std)
{
	STR("END\n");
	(void)read_std;
	return (1);
}
