/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:12:15 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/18 17:24:13 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char	*fill(char *str, t_fmtid id)
{
	size_t	len;
	char	*newstr;
	char	c;
	size_t	offset;

	len = ft_strlen(str);
	if (len < id.fp)
	{
		c = ' ';
		if (id.flag != NULL && !ft_strchr(id.flag, '-') &&
		(!ft_strchr(id.flag, '.') || id.lp < 0) && ft_strchr(id.flag, '0'))
			c = '0';
		newstr = (char *)ft_memset(ft_strnew(id.fp), c, id.fp);
		offset = id.flag && ft_strchr(id.flag, '-') ? 0 : id.fp - len;
		ft_memcpy(newstr + offset, str, len);
		ft_memdel((void **)&str);
		return (newstr);
	}
	return (str);
}
