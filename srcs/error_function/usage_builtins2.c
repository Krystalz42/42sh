//
// Created by Alexandre ROULIN on 11/14/17.
//

#include <sh.h>

uint8_t				usage_unsetenv(void)
{
	ft_putstr_fd(UNSET, STDERR_FILENO);
	return (0);
}

uint8_t				usage_setenv(void)
{
	ft_putstr_fd(SET, STDERR_FILENO);
	return (0);
}

uint8_t				usage_foreground(void)
{
	ft_putstr_fd(FG_JOBSSPEC, STDERR_FILENO);
	ft_putstr_fd(FG_DEFAULT, STDERR_FILENO);
	return (0);
}

uint8_t				usage_background(void)
{
	ft_putstr_fd(BG_JOBSSPEC, STDERR_FILENO);
	ft_putstr_fd(BG_DEFAULT, STDERR_FILENO);
	return (0);
}

uint8_t				usage_cd(void)
{
	ft_putstr_fd(CD_DEFAULT, STDERR_FILENO);
	return (0);
}
