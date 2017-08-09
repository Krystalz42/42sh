/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 19:25:49 by aroulin           #+#    #+#             */
/*   Updated: 2017/04/18 19:27:36 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

char	*fill_last(char *str, t_fmtid id)
{
	size_t	len;
	char	*newstr;

	len = ft_strlen(str);
	if ((long)len < id.lp && id.lp >= 0)
	{
		newstr = (char *)ft_memset(ft_strnew(id.lp), '0', id.lp);
		ft_memcpy(newstr + (id.lp - len), str, len);
		ft_memdel((void **)&str);
		return (newstr);
	}
	return (str);
}
