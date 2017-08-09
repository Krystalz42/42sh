/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:43:27 by jgraille          #+#    #+#             */
/*   Updated: 2017/03/05 20:18:46 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrtab(char **tab, char separator)
{
	while (*tab)
	{
		ft_putstr(*tab);
		ft_putchar(separator);
		tab++;
	}
}
