/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_sign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:40:20 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/18 17:26:11 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

char	*fill_sign(char *str, t_fmtid id)
{
	int		i;
	char	*tmp;
	char	*sign;

	i = 0;
	if (id.sign != 0)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '0' && (long)ft_strlen(str) - i > id.lp && str[i + 1])
			i++;
		if (i > 0 || ft_strlen(str) == id.fp)
			str[i - (i > 0)] = id.sign;
		else
		{
			sign = ft_strnew(1);
			sign[0] = id.sign;
			tmp = ft_strjoin(sign, str);
			ft_memdel((void **)&str);
			ft_memdel((void**)&sign);
			return (tmp);
		}
	}
	return (str);
}
