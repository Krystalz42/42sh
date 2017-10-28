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

uint8_t				builtin_help(char **command, char **env)
{
	(void)command;
	(void)env;
	ft_putstr("Usage for env :\n");
	usage_env();
	ft_putstr("Usage for hash :\n");
	usage_hash();
	ft_putstr("Usage for history :\n");
	usage_history();
	ft_putstr("Usage for jobs :\n");
	usage_jobs();
	ft_putstr("Usage for kill :\n");
	usage_kill();
	help_move();
	help_history();
	help_kill_and_yank();
	return (0);
}