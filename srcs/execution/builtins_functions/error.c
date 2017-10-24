/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 18:43:55 by sbelazou          #+#    #+#             */
/*   Updated: 2017/10/24 15:37:37 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		ft_error(char *var, char *msg, int ret)
{
	ft_putstr_fd(RED, 2);
	ft_putstr_fd(var, 2);
	ft_putendl_fd(msg, 2);
	ft_putstr_fd(RST, 2);
	return (ret);
}
