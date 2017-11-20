/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:19 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/20 15:42:20 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int			usage_help(void)
{
	ft_putstr(H_HJ) && ft_putstr(H_HE);
	ft_putstr(H_HK) && ft_putstr(H_HH);
	ft_putstr(H_HB) && ft_putstr(H_HS);
	ft_putstr(H_HU) && ft_putstr(H_HF);
	ft_putstr(H_HG) && ft_putstr(H_HC);
	ft_putstr(H_HM);
	return (0);
}

static int			print_help(int option)
{
	(option & OPT_R) && help_move() && help_history() && help_kill_and_yank();
	(option & OPT_J) && ft_putstr(H_J) && usage_jobs();
	(option & OPT_E) && ft_putstr(H_E) && usage_env();
	(option & OPT_A) && ft_putstr(H_B) && usage_hash();
	(option & OPT_H) && ft_putstr(H_H) && usage_history();
	(option & OPT_K) && ft_putstr(H_K) && usage_kill();
	(option & OPT_S) && ft_putstr(H_S) && usage_setenv();
	(option & OPT_U) && ft_putstr(H_U) && usage_unsetenv();
	(option & OPT_B) && ft_putstr(H_G) && usage_background();
	(option & OPT_F) && ft_putstr(H_F) && usage_foreground();
	(option & OPT_C) && ft_putstr(H_C) && usage_cd();
	return (0);
}

int					get_option(char **cmd, int option)
{
	int			index;
	int			table;

	table = 0;
	while (cmd[++table] && !(index = 0))
		while (cmd[table][++index])
		{
			if (potential_option("-jebhksugfcra", cmd[table][index]) == 0)
				return (error_msg(UHELP, BAD_OPTION, cmd[table] + index) - 2);
			option |= cmd[table][index] == 'j' ? OPT_J : 0;
			option |= cmd[table][index] == 'e' ? OPT_E : 0;
			option |= cmd[table][index] == 'b' ? OPT_B : 0;
			option |= cmd[table][index] == 'h' ? OPT_H : 0;
			option |= cmd[table][index] == 'k' ? OPT_K : 0;
			option |= cmd[table][index] == 's' ? OPT_S : 0;
			option |= cmd[table][index] == 'u' ? OPT_U : 0;
			option |= cmd[table][index] == 'a' ? OPT_A : 0;
			option |= cmd[table][index] == 'f' ? OPT_F : 0;
			option |= cmd[table][index] == 'c' ? OPT_C : 0;
			option |= cmd[table][index] == 'r' ? OPT_R : 0;
		}
	return (option);
}

uint8_t				builtin_help(t_node *node, int info)
{
	int			option;

	(void)info;
	option = 0;
	if (node->content->command[1] == NULL)
		return (usage_help());
	else if (node->content->command[1] && node->content->command[1][0] == '-')
		if ((option = get_option(node->content->command, 0)) == -1)
			return (1);
	return (print_help(option));
}
