/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:14:05 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/08 13:20:22 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int	ft_ustrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i] && ft_toupper(s1[i]) == ft_toupper(s2[i]))
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char)ft_toupper(s1[i])
				- (unsigned char)ft_toupper(s2[i]));
}
