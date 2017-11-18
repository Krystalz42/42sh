/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_builtins2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:07:25 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/18 17:54:57 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t				usage_unsetenv(void)
{
	ft_putstr_fd("[name]                  \
: Unset the variable in environement.\n", STDERR_FILENO);
	return (0);
}

uint8_t				usage_setenv(void)
{
	ft_putstr_fd("[name=value]            \
: Set the variable in environement.\n", STDERR_FILENO);
	return (0);
}

uint8_t				usage_foreground(void)
{
	ft_putstr_fd("%[number ..]            \
: Put the specified jobs in foreground.\n", STDERR_FILENO);
	ft_putstr_fd("otherwise               \
: Put the most large jobs in foreground.\n", STDERR_FILENO);
	return (0);
}

uint8_t				usage_background(void)
{
	ft_putstr_fd("%[number ..]            \
: Put the specified jobs in background.\n", STDERR_FILENO);
	ft_putstr_fd("otherwise               \
: Put the most large jobs in background.\n", STDERR_FILENO);
	return (0);
}

uint8_t				usage_cd(void)
{
	ft_putstr_fd("[path]				  \
: Change the current directory.\n", STDERR_FILENO);
	return (0);
}
