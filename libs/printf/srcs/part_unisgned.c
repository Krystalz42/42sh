/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_unisgned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf.h>
#include <libft.h>

char		*part_unsigned(t_fmtid *id, va_list *ap)
{
	char	*str;
	char	*tmp;

	tmp = conv_un(*id, ap);
	if (*tmp == '0' && ft_strlen(tmp) == 1 && id->flag &&
	ft_strchr(id->flag, '.'))
		*tmp = 0;
	str = ft_strdup(tmp);
	ft_memdel((void **)&tmp);
	str = fill_last(str, *id);
	str = fill(str, *id);
	return (str);
}
