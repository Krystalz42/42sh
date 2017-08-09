/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:18:30 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/18 17:26:21 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

char	*fill_str(char *str, t_fmtid id)
{
	size_t	len;
	char	*newstr;
	char	c;
	size_t	offset;

	len = (id.dif != NULL && id.dif[0] == 'N' ? 1 : 0) + ft_strlen(str);
	if (len < id.fp)
	{
		c = ' ';
		if (!ft_strchr(id.flag, '-') && ft_strchr(id.flag, '0'))
			c = '0';
		newstr = (char *)ft_memset(ft_strnew(id.fp), c, id.fp);
		offset = id.flag && ft_strchr(id.flag, '-') ? 0 : id.fp - len;
		ft_memcpy(newstr + offset, str, len);
		ft_memdel((void **)&str);
		return (newstr);
	}
	return (str);
}
