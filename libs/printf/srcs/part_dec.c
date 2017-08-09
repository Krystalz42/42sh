/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_dec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:33:09 by aroulin           #+#    #+#             */
/*   Updated: 2017/04/18 17:27:45 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

static char			*add_e(char *str, char arg)
{
	char *tmp;

	if (arg == 'e')
		tmp = ft_strjoin(str, "e+00");
	else
		tmp = ft_strjoin(str, "E+00");
	ft_memdel((void **)&str);
	return (tmp);
}

char				*part_dec(t_fmtid id, va_list *ap)
{
	char	*str;
	double	nbr;

	nbr = va_arg(*ap, double);
	if (id.flag == NULL || !ft_strchr(id.flag, '.') || id.lp < 0)
		id.lp = 6;
	str = ft_ftoa(nbr, id.lp);
	if (ft_strchr("eE", id.arg))
		str = add_e(str, id.arg);
	str = fill(str, id);
	return (str);
}
