/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:19:07 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/18 17:49:22 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t				usage_kill(void)
{
	ft_putstr_fd("-l                      \
: If no operand is given, list the signal names; otherwise, write the \
signal name corresponding to exit_status.\n", STDERR_FILENO);
	ft_putstr_fd("-[signal_name]   pid .. \
: A symbolic signal name specifying the signal to be sent instead of the \
default TERM.\n", STDERR_FILENO);
	ft_putstr_fd("-[signal_number] pid .. \
: A non-negative decimal integer, specifying the signal to be sent instead \
of the default TERM.\n", STDERR_FILENO);
	return (0);
}

uint8_t				usage_history(void)
{
	ft_putstr_fd("-c                      \
: Clear the history list.\n", STDERR_FILENO);
	ft_putstr_fd("-d offset               \
: Delete the history entry at position offset.\n", STDERR_FILENO);
	ft_putstr_fd("-r [pathname]           \
: Read the history file and append its contents to the \
history list.\n", STDERR_FILENO);
	ft_putstr_fd("-w [pathname]           \
: Write out the current history list to the history file.\n", STDERR_FILENO);
	ft_putstr_fd("otherwise               \
: Print history list\n", STDERR_FILENO);
	return (0);
}

uint8_t				usage_jobs(void)
{
	ft_putstr_fd("-l                      \
: List process IDs in addition to the normal information.\n", STDERR_FILENO);
	ft_putstr_fd("-p                      \
: List only the	process ID of the job’s process group \
leader.\n", STDERR_FILENO);
	ft_putstr_fd("-r                      \
: Display only running jobs.\n", STDERR_FILENO);
	ft_putstr_fd("-s                      \
: Display only stopped jobs.\n", STDERR_FILENO);
	ft_putstr_fd("otherwise               \
: Display all jobs.\n", STDERR_FILENO);
	return (0);
}

uint8_t				usage_env(void)
{
	ft_putstr_fd("-i [name=value ...]     \
: Add [name=value] to empty env temporarily.\n", STDERR_FILENO);
	ft_putstr_fd("-u [name]               \
: Remove [name] to own env temporarily.\n", STDERR_FILENO);
	ft_putstr_fd("[name=value ...]        \
: Add [name=value] to own env temporarily.\n", STDERR_FILENO);
	return (0);
}

uint8_t				usage_hash(void)
{
	ft_putstr_fd("-r                      \
: Reset the hash table.\n", STDERR_FILENO);
	ft_putstr_fd("otherwise               \
: Print the hash list.\n", STDERR_FILENO);
	return (0);
}
