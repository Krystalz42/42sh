/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_builtins2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:07:25 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 15:07:28 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t				usage_unsetenv(void)
{
	ft_putstr_fd(UNSET, STDERR_FILENO);
	return (0);
}

uint8_t				usage_setenv(void)
{
	ft_putstr_fd(SET, STDERR_FILENO);
	return (0);
}

uint8_t				usage_foreground(void)
{
	ft_putstr_fd(FG_JOBSSPEC, STDERR_FILENO);
	ft_putstr_fd(FG_DEFAULT, STDERR_FILENO);
	return (0);
}

uint8_t				usage_background(void)
{
	ft_putstr_fd(BG_JOBSSPEC, STDERR_FILENO);
	ft_putstr_fd(BG_DEFAULT, STDERR_FILENO);
	return (0);
}

uint8_t				usage_cd(void)
{
	ft_putstr_fd(CD_DEFAULT, STDERR_FILENO);
	return (0);
}
