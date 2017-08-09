/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrtab_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 11:13:50 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/23 11:17:01 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrtab_fd(char **tab, char separator, int fd)
{
	while (*tab)
	{
		ft_putstr_fd(*tab, fd);
		ft_putchar_fd(separator, fd);
		tab++;
	}
}
