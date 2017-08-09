/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:44:01 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/18 17:22:39 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

char	*cut_str(char *str, t_fmtid id)
{
	size_t	len;
	char	*tmp;

	len = 0;
	if (id.lp < 0)
		return (str);
	while (str[len] && (long)len < 1 + id.lp)
		len++;
	if (id.flag && ft_strchr(id.flag, '.') && (long)len > id.lp)
	{
		tmp = ft_strsub(str, 0, id.lp);
		ft_memdel((void **)&str);
		return (tmp);
	}
	return (str);
}
