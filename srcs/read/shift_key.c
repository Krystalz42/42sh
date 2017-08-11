/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/11 06:34:02 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/11 06:41:25 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		shift_up_key(t_read **read_std)
{
	STR("SHIFT UP\n");
	(void)read_std;
	return (1);
}

int		shift_down_key(t_read **read_std)
{
	STR("SHIFT DO\n");
	(void)read_std;
	return (1);
}

int		shift_left_key(t_read **read_std)
{
	STR("SHIFT LE\n");
	(void)read_std;
	return (1);
}

int		shift_right_key(t_read **read_std)
{
	STR("SHIFT RI\n");
	(void)read_std;
	return (1);
}

