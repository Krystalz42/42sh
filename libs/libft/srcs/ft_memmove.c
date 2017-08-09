/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:34:51 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/28 16:19:31 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*cpy_src;
	char	*cpy_dst;

	cpy_src = (char *)src;
	cpy_dst = (char *)dst;
	while (n != 0)
	{
		if (src > dst)
		{
			*(cpy_dst) = *(cpy_src);
			cpy_src++;
			cpy_dst++;
		}
		else
			*(cpy_dst + n - 1) = *(cpy_src + n - 1);
		n--;
	}
	return (dst);
}
