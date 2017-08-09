/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 12:16:55 by aroulin           #+#    #+#             */
/*   Updated: 2017/04/18 17:21:40 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

char	*clear_flag(char *flag)
{
	size_t	ind;
	char	*tmp;

	ind = 0;
	while (flag && flag[ind] && !ft_strchr("hljz", flag[ind]))
		ind++;
	if (flag && flag[ind] && ft_strchr("hljz", flag[ind]))
	{
		if (flag[ind] == flag[ind + 1])
			if (flag[ind + 2] && ft_strchr("hljz", flag[ind + 2]))
			{
				flag[ind] = flag[ind + 2];
				tmp = ft_str_charnout(flag, "hljz", ind + 1);
				ft_memdel((void **)&flag);
				return (tmp);
			}
		if (flag[ind] == flag[ind + 1])
			tmp = ft_str_charnout(flag, "hljz", ind + 2);
		else
			tmp = ft_str_charnout(flag, "hljz", ind + 1);
		ft_memdel((void **)&flag);
		return (tmp);
	}
	return (flag);
}
