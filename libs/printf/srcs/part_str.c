/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:36:31 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/18 17:28:23 by aroulin          ###   ########.fr       */
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
