/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tank.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 18:48:11 by aroulin           #+#    #+#             */
/*   Updated: 2017/04/18 17:26:45 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

char	*fill_tank(char *str, t_fmtid id)
{
	char	*newstr;
	char	c;

	if (id.fp > 0)
	{
		c = id.flag && ft_strchr(id.flag, '0') ? '0' : ' ';
		newstr = (char *)ft_memset(ft_strnew(id.fp - 1), c, id.fp - 1);
		ft_memdel((void **)&str);
		return (newstr);
	}
	return (str);
}
