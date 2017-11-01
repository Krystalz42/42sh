/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:19:07 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:19:09 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t				usage_kill(void)
{
	ft_putstr_fd(KILL_L, STDERR_FILENO);
	ft_putstr_fd(KILL_NAME, STDERR_FILENO);
	ft_putstr_fd(KILL_NUMBER, STDERR_FILENO);
	return (0);
}

uint8_t				usage_history(void)
{
	ft_putstr_fd(HISTORY_L, STDERR_FILENO);
	ft_putstr_fd(HISTORY_D, STDERR_FILENO);
	ft_putstr_fd(HISTORY_R, STDERR_FILENO);
	ft_putstr_fd(HISTORY_W, STDERR_FILENO);
	ft_putstr_fd(HISTORY_DEFAULT, STDERR_FILENO);
	return (0);
}

uint8_t				usage_jobs(void)
{
	ft_putstr_fd(JOBS_L, STDERR_FILENO);
	ft_putstr_fd(JOBS_P, STDERR_FILENO);
	ft_putstr_fd(JOBS_R, STDERR_FILENO);
	ft_putstr_fd(JOBS_S, STDERR_FILENO);
	ft_putstr_fd(JOBS_DEFAULT, STDERR_FILENO);
	return (0);
}

uint8_t				usage_env(void)
{
	ft_putstr_fd(ENV_I, STDERR_FILENO);
	ft_putstr_fd(ENV_U, STDERR_FILENO);
	ft_putstr_fd(ENV_DEFAULT, STDERR_FILENO);
	return (0);
}

uint8_t				usage_hash(void)
{
	ft_putstr_fd(HASH_R, STDERR_FILENO);
	ft_putstr_fd(HASH_DEFAULT, STDERR_FILENO);
	return (0);
}
