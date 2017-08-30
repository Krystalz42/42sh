/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>
#include <unistd.h>

int		put_format(char **format)
{
	size_t ind;

	ind = 0;
	while ((*format)[ind] && !ft_strchr("%{", (*format)[ind]))
		ind++;
	write(1, *format, ind);
	(*format) += ind;
	return (ind);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	size_t		count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (!ft_strchr("%{", *format))
			count += put_format((char **)&format);
		else
			count += str_special(format_identifier((char **)&format), &ap);
	}
	va_end(ap);
	return (count);
}
