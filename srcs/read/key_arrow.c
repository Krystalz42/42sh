/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 03:27:42 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/11 06:30:08 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			arrow_left(t_read **read_std)
{
	STR("AL\n");
	(void)read_std;
	return (1);
}

int			arrow_right(t_read **read_std)
{
	STR("AR\n");
	(void)read_std;
	return (1);
}

int			arrow_up(t_read **read_std)
{
	STR("AU\n");
	(void)read_std;
	return (1);
}

int			arrow_down(t_read **read_std)
{
	STR("AD\n");
	(void)read_std;
	return (1);
}
