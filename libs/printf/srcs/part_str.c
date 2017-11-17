/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 15:02:22 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf.h>
#include <libft.h>

char		*part_str(t_fmtid id, va_list *ap)
{
	char *str;

	str = va_arg(*ap, char*);
	if (str == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(str);
	str = cut_str(str, id);
	str = fill_str(str, id);
	return (str);
}
