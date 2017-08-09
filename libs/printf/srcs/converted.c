/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:35:10 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/18 17:22:12 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char		*conv_base(t_fmtid id, va_list *ap)
{
	if (ft_strchr("xX", id.arg) || ft_islower(id.arg))
	{
		if (ft_strstr(id.flag, "hh") != NULL)
			return (ft_uitoa((unsigned char)va_arg(*ap, unsigned int)));
		if (ft_strchr(id.flag, 'l') != NULL)
			return (ft_ultoa(va_arg(*ap, unsigned long)));
		if (ft_strchr(id.flag, 'h') != NULL)
			return (ft_ustoa((unsigned short)va_arg(*ap, unsigned int)));
		if (ft_strstr(id.flag, "ll") != NULL)
			return (ft_ulltoa(va_arg(*ap, unsigned long long)));
		if (ft_strchr(id.flag, 'j') != NULL)
			return (ft_ultoa(va_arg(*ap, unsigned long)));
		if (ft_strchr(id.flag, 'z') != NULL)
			return (ft_ultoa(va_arg(*ap, unsigned long)));
		return (ft_uitoa(va_arg(*ap, unsigned int)));
	}
	else
		return (ft_ultoa(va_arg(*ap, unsigned long)));
}

char		*converted(t_fmtid id, va_list *ap)
{
	if (ft_islower(id.arg))
	{
		if (ft_strstr(id.flag, "hh") != NULL)
			return (ft_itoa((char)va_arg(*ap, int)));
		if (ft_strstr(id.flag, "h") != NULL)
			return (ft_stoa((short)va_arg(*ap, int)));
		if (ft_strstr(id.flag, "ll") != NULL)
			return (ft_lltoa(va_arg(*ap, long long)));
		if (ft_strstr(id.flag, "l") != NULL)
			return (ft_ltoa(va_arg(*ap, long)));
		if (ft_strstr(id.flag, "j") != NULL)
			return (ft_ltoa(va_arg(*ap, long)));
		if (ft_strstr(id.flag, "z") != NULL)
			return (ft_lltoa(va_arg(*ap, size_t)));
		return (ft_itoa(va_arg(*ap, int)));
	}
	else
		return (ft_ltoa(va_arg(*ap, long)));
}

char		*conv_un(t_fmtid id, va_list *ap)
{
	if (ft_islower(id.arg))
	{
		if (ft_strstr(id.flag, "hh") != NULL)
			return (ft_uitoa((unsigned char)va_arg(*ap, unsigned int)));
		if (ft_strchr(id.flag, 'l') != NULL)
			return (ft_ultoa(va_arg(*ap, unsigned long)));
		if (ft_strchr(id.flag, 'h') != NULL)
			return (ft_ustoa((unsigned short)va_arg(*ap, unsigned int)));
		if (ft_strstr(id.flag, "ll") != NULL)
			return (ft_ulltoa(va_arg(*ap, unsigned long long)));
		if (ft_strchr(id.flag, 'j') != NULL)
			return (ft_ultoa(va_arg(*ap, unsigned long)));
		if (ft_strchr(id.flag, 'z') != NULL)
			return (ft_ultoa(va_arg(*ap, unsigned long)));
		return (ft_uitoa(va_arg(*ap, unsigned int)));
	}
	else
		return (ft_ultoa(va_arg(*ap, unsigned long)));
}
