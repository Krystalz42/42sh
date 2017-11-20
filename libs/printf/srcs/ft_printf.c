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

#include <libftprintf.h>

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		len;
	char	*ret;

	if (!format || !*format)
		return (0);
	va_start(ap, format);
	len = ft_vasprintf(&ret, format, ap);
	write(1, ret, len);
	free(ret);
	va_end(ap);
	return (len);
}

int		ft_vasprintf(char **ret, const char *format, va_list ap)
{
	if (*format == '\0')
		*ret = ft_strnew(0);
	if (!ret || !format || !*format)
		return (0);
	if (ft_strchr(format, '%') == NULL)
	{
		if ((*ret = ft_strdup(format)) == NULL)
			return (-1);
		return (ft_strlen(*ret));
	}
	return (ft_strprintf(ret, format, ap));
}

int		ft_sprintf(char *str, const char *format, ...)
{
	va_list ap;
	int		len;
	char	*ret;

	if (!str || !format)
		return (0);
	va_start(ap, format);
	len = ft_vasprintf(&ret, format, ap);
	ft_strcpy(str, ret);
	free(ret);
	va_end(ap);
	return (len);
}

int		ft_snprintf(char *str, size_t size, const char *format, ...)
{
	va_list ap;
	int		len;
	char	*ret;

	if (!str || !format)
		return (0);
	va_start(ap, format);
	len = ft_vasprintf(&ret, format, ap);
	if (size == 0)
		return (len);
	else if (size - 1 == 0)
		str[0] = '\0';
	ft_strncpy(str, ret, size - 1);
	free(ret);
	va_end(ap);
	return (len);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list ap;
	int		len;
	char	*ret;

	if (!format || !*format || fd < 0)
		return (0);
	va_start(ap, format);
	len = ft_vasprintf(&ret, format, ap);
	write(fd, ret, len);
	free(ret);
	va_end(ap);
	return (len);
}
