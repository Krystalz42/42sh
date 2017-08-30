/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

char	*fill_pointer(char *str, t_fmtid id)
{
	char	*hash;
	size_t	i;
	size_t	len;
	char	*tmp;

	if (str == NULL)
		return (NULL);
	hash = ft_strdup("0X");
	len = ft_strlen(str);
	i = 0;
	while (str[i] == ' ')
		i++;
	if (i >= ft_strlen(hash) && id.flag && !ft_strchr(id.flag, '-'))
		ft_memcpy(str + i - ft_strlen(hash), hash, ft_strlen(hash));
	else
	{
		tmp = ft_strjoin(hash, str + i);
		ft_memdel((void **)&str);
		str = tmp;
	}
	ft_memdel((void**)&hash);
	return (str);
}
