/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:19 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:22:21 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int			help_move(void)
{
	ft_putstr(H_MOVE);
	ft_putstr(H_CA);
	ft_putstr(H_CE);
	ft_putstr(H_CF);
	ft_putstr(H_CB);
	ft_putstr(H_MF);
	ft_putstr(H_MB);
	ft_putstr(H_CL);
	return (1);
}

static int			help_history(void)
{
	ft_putstr(H_HISTORY);
	ft_putstr(H_CP);
	ft_putstr(H_CN);
	ft_putstr(H_CR);
	ft_putstr(H_CD);
	ft_putstr(H_MU);
	ft_putstr(H_ML);
	ft_putstr(H_MC);
	return (1);
}

static int			help_kill_and_yank(void)
{
	ft_putstr(H_KILL_AND_YANK);
	ft_putstr(H_CK);
	ft_putstr(H_MD);
	ft_putstr(H_MDEL);
	ft_putstr(H_MY);
	return (1);
}

static int			print_help(int option)
{
	if (option & 1)
	{
		ft_putstr(H_HJ);
		ft_putstr(H_HE);
		ft_putstr(H_HK);
		ft_putstr(H_HH);
		ft_putstr(H_HB);
		ft_putstr(H_HS);
		ft_putstr(H_HU);
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
	}
	return (1);
}

uint8_t				builtin_help(t_node *node, int info __attribute__((unused)))
{
	int			option;
	int			index;

	option = 0;
	index = 0;
	if (node->content->command[1] && !ft_strcmp(node->content->command[1], HELP))
		option = 1;
	else if (node->content->command[1] && node->content->command[1][0] == '-')
	{
		while (node->content->command[1][index])
		{
			option += node->content->command[1][index] == 'j' && !(option & 2) ? 2 : 0;
			option += node->content->command[1][index] == 'e' && !(option & 4) ? 4 : 0;
			option += node->content->command[1][index] == 'b' && !(option & 8) ? 8 : 0;
			option += node->content->command[1][index] == 'h' && !(option & 16) ? 16 : 0;
			option += node->content->command[1][index] == 'k' && !(option & 32) ? 32 : 0;
			option += node->content->command[1][index] == 's' && !(option & 64) ? 64 : 0;
			option += node->content->command[1][index] == 'u' && !(option & 128) ? 128 : 0;
			option += node->content->command[1][index] == 'g' && !(option & 256) ? 256 : 0;
			option += node->content->command[1][index] == 'f' && !(option & 256) ? 256 : 0;
			index++;
		}
	}
	(option == 0) && help_move();
	(option == 0) && help_history();
	(option == 0) && help_kill_and_yank();
	(option) && print_help(option);
	return (0);
}
