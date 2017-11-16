/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:19 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/15 19:43:24 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int			print_help(int option)
{
	if (option & 1)
	{
		ft_putstr(H_HJ) && ft_putstr(H_HE);
		ft_putstr(H_HK) && ft_putstr(H_HH);
		ft_putstr(H_HB) && ft_putstr(H_HS);
		ft_putstr(H_HU) && ft_putstr(H_HF);
		ft_putstr(H_HG) && ft_putstr(H_HC);
	}
	else
	{
		(option & 2) && ft_putstr(H_J) && usage_jobs();
		(option & 4) && ft_putstr(H_E) && usage_env();
		(option & 8) && ft_putstr(H_B) && usage_hash();
		(option & 16) && ft_putstr(H_H) && usage_history();
		(option & 32) && ft_putstr(H_K) && usage_kill();
		(option & 64) && ft_putstr(H_S) && usage_setenv();
		(option & 128) && ft_putstr(H_U) && usage_unsetenv();
		(option & 256) && ft_putstr(H_G) && usage_background();
		(option & 512) && ft_putstr(H_F) && usage_foreground();
		(option & 1024) && ft_putstr(H_C) && usage_cd();
	}
	return (1);
}

int					get_option(char **cmd, int option)
{
	int			index;
	int			table;

	option = 0;
	table = 0;
	while (cmd[++table] && !(index = 0))
	{
		while (cmd[table][index])
		{
			if (potential_option("-jebhksugfc", cmd[table][index]) == 0)
				return (error_msg(UHELP, BAD_OPTION, cmd[table] + index) - 2);
			option += cmd[table][index] == 'j' && !(option & 2) ? 2 : 0;
			option += cmd[table][index] == 'e' && !(option & 4) ? 4 : 0;
			option += cmd[table][index] == 'b' && !(option & 8) ? 8 : 0;
			option += cmd[table][index] == 'h' && !(option & 16) ? 16 : 0;
			option += cmd[table][index] == 'k' && !(option & 32) ? 32 : 0;
			option += cmd[table][index] == 's' && !(option & 64) ? 64 : 0;
			option += cmd[table][index] == 'u' && !(option & 128) ? 128 : 0;
			option += cmd[table][index] == 'g' && !(option & 256) ? 256 : 0;
			option += cmd[table][index] == 'f' && !(option & 512) ? 512 : 0;
			option += cmd[table][index] == 'c' && !(option & 1024) ? 1024 : 0;
			index++;
		}
		index++;
	}
	return (option);
}

uint8_t				builtin_help(t_node *node, int info)
{
	int			option;

	option = 0;
	if (node->content->command[1] &&
			!ft_strcmp(node->content->command[1], HELP))
		option = 1;
	else if (node->content->command[1] && node->content->command[1][0] == '-')
		if ((option = get_option(node->content->command, info)) == -1)
			return (var_return(1));
	(option == 0) && help_move();
	(option == 0) && help_history();
	(option == 0) && help_kill_and_yank();
	(option) && print_help(option);
	return (0);
}
