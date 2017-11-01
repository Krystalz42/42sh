/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_kill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:40 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:22:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static const t_signal	g_info[] = {
		(t_signal){SIGHUP, "HUP"},
		(t_signal){SIGINT, "INT"},
		(t_signal){SIGQUIT, "QUIT"},
		(t_signal){SIGILL, "ILL"},
		(t_signal){SIGTRAP, "TRAP"},
		(t_signal){SIGABRT, "ABRT"},
		(t_signal){SIGEMT, "EMT"},
		(t_signal){SIGFPE, "FPE"},
		(t_signal){SIGKILL, "KILL"},
		(t_signal){SIGBUS, "BUS"},
		(t_signal){SIGSEGV, "SEGV"},
		(t_signal){SIGSYS, "SYS"},
		(t_signal){SIGPIPE, "PIPE"},
		(t_signal){SIGALRM, "ALRM"},
		(t_signal){SIGTERM, "TERM"},
		(t_signal){SIGURG, "URG"},
		(t_signal){SIGSTOP, "STOP"},
		(t_signal){SIGTSTP, "TSTP"},
		(t_signal){SIGCONT, "CONT"},
		(t_signal){SIGCHLD, "CHLD"},
		(t_signal){SIGTTIN, "TTIN"},
		(t_signal){SIGTTOU, "TTOU"},
		(t_signal){SIGIO, "IO"},
		(t_signal){SIGXCPU, "XCPU"},
		(t_signal){SIGXFSZ, "XFSZ"},
		(t_signal){SIGVTALRM, "VTALRM"},
		(t_signal){SIGPROF, "PROF"},
		(t_signal){SIGWINCH, "WINCH"},
		(t_signal){SIGINFO, "INFO"},
		(t_signal){SIGUSR1, "USR1"},
		(t_signal){SIGUSR2, "USR2"},
		(t_signal){0, NULL}
};

uint8_t			signal_from_str(char *status)
{
	size_t			index;

	index = 0;
	while (g_info[index].signal)
	{
		if (ft_strcmp(status, g_info[index].status) == 0)
		{
			ft_putnbr(g_info[index].signal);
			ft_putchar(10);
			return (0);
		}
		index++;
	}
	return (error_builtin(KILL, UNKNOWN, status));
}

uint8_t			signal_from_int(uint8_t signal)
{
	size_t			index;

	index = 0;
	while (g_info[index].signal)
	{
		if (g_info[index].signal == signal)
		{
			ft_putnbr(g_info[index].signal);
			ft_putchar(10);
			return (0);
		}
		index++;
	}
	return (error_builtin(KILL, UNKNOWN, NULL));
}

uint8_t			all_signal(void)
{
	size_t			index;

	index = 0;
	while (g_info[index].signal)
	{
		ft_putstr(g_info[index].status);
		ft_putchar(32);
		index++;
	}
	ft_putchar(10);
	return (0);
}

uint8_t			kill_process(char *string1, char *string2)
{
	int					signal;
	int					index;

	index = -1;
	signal = SIGTERM;
	if (string1 && ft_strisdigit(string1 + 1))
		signal = ft_atoi(string1 + 1);
	else if (string1 && ft_strisalpha(string1 + 1))
	{
		while (g_info[++index].signal)
			if (ft_strcmp(g_info[index].status, string1 + 1) == 0)
				signal = g_info[index].signal;
	}
	if (ft_strisdigit(string2))
	{
		log_trace("Return [%d] of %d",kill(0, ft_atoi(string2)), ft_atoi(string2));
		if (kill(ft_atoi(string2), 0) != 0)
			return (error_builtin(KILL, NO_PROCESS, string2));
		else
			return (uint8_t)(kill(ft_atoi(string2), signal));
	}
	else
		return (error_builtin(KILL, ILLEGAL, string2));
}

uint8_t			builtin_kill(t_node *node, int info)
{
	(void)info;
	if (node->content->command[1])
	{
		if (node->content->command[1][0] == '-')
		{
			if (ft_strcmp(node->content->command[1], HELP) == 0)
				return (var_return(usage_kill()));
			else if (node->content->command[1][1] == 'l')
			{
				if (node->content->command[2] && ft_strisdigit(node->content->command[2] + 1))
					return (var_return(signal_from_int((uint8_t)
													ft_atoi(node->content->command[2] + 1))));
				else if (node->content->command[2] && ft_strisalpha(node->content->command[2] + 1))
					return (var_return(signal_from_str(node->content->command[2] + 1)));
				else
					return (var_return(all_signal()));
			}
			else if (node->content->command[2])
				return (var_return(kill_process(node->content->command[1], node->content->command[2])));
			else
				return (var_return(error_builtin(KILL, UNKNOWN, node->content->command[1] + 1)));
		}
		else
			return (var_return(kill_process(NULL, node->content->command[1])));
	}
	return (var_return(error_builtin(KILL, NO_ARGS, NULL)));
}
