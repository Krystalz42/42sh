//
// Created by Alexandre ROULIN on 10/28/17.
//

#include <sh.h>

static void			help_move(void)
{
	ft_putstr(H_MOVE);
	ft_putstr(H_CA);
	ft_putstr(H_CE);
	ft_putstr(H_CF);
	ft_putstr(H_CB);
	ft_putstr(H_MF);
	ft_putstr(H_MB);
	ft_putstr(H_CL);
}

static void			help_history(void)
{
	ft_putstr(H_HISTORY);
	ft_putstr(H_CP);
	ft_putstr(H_CN);
	ft_putstr(H_CR);
	ft_putstr(H_CD);
	ft_putstr(H_MU);
	ft_putstr(H_ML);
	ft_putstr(H_MC);
}

static void			help_kill_and_yank(void)
{
	ft_putstr(H_KILL_AND_YANK);
	ft_putstr(H_CK);
	ft_putstr(H_MD);
	ft_putstr(H_MDEL);
	ft_putstr(H_MY);
}

static void			print_help(int option)
{
	if (option & 1)
	{
		ft_putstr(H_HJ);
		ft_putstr(H_HE);
		ft_putstr(H_HK);
		ft_putstr(H_HH);
		ft_putstr(H_HB);
	}
	else
	{
		(option & 2) && ft_putstr(H_J) &&  usage_jobs();
		(option & 4) && ft_putstr(H_E) && usage_env();
		(option & 8) && ft_putstr(H_B) && usage_hash();
		(option & 16) && ft_putstr(H_H) && usage_history();
		(option & 32) && ft_putstr(H_K) && usage_kill();
	}
}

uint8_t				builtin_help(char **command, char **env)
{
	int			option;
	int			index;

	option = 0;
	index = 0;
	(void)env;
	if (command[1] && !ft_strcmp(command[1], HELP))
		print_help(1);
	else if (command[1] && command[1][0] == '-')
	{
		while (command[1][index])
		{
			option += command[1][index] == 'j' && !(option & 2) ? 2 : 0;
			option += command[1][index] == 'e' && !(option & 4) ? 4 : 0;
			option += command[1][index] == 'b' && !(option & 8) ? 8 : 0;
			option += command[1][index] == 'h' && !(option & 16) ? 16 : 0;
			option += command[1][index] == 'k' && !(option & 32) ? 32 : 0;
			index++;
		}
		print_help(option);
	}
	else
	{
		help_move();
		help_history();
		help_kill_and_yank();
	}
	return (0);
}