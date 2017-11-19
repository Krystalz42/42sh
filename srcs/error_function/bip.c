/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:15:14 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/24 15:08:30 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			bip(void)
{
	CHAR_FD(7, 2);
	return (1);
}

uint8_t		error_msg(char *from, char *error, char *args)
{
	ft_putstr_fd(from, STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd(args, STDERR_FILENO);
	ft_putchar_fd(10, STDERR_FILENO);
	return (var_return(1));
}
