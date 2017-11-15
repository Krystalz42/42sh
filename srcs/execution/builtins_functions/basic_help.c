
#include <sh.h>

int			help_move(void)
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

int			help_history(void)
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

int			help_kill_and_yank(void) {
	ft_putstr(H_KILL_AND_YANK);
	ft_putstr(H_CK);
	ft_putstr(H_MD);
	ft_putstr(H_MDEL);
	ft_putstr(H_MY);
	return (1);
}
