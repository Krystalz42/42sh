//
// Created by Alexandre ROULIN on 10/14/17.
//

#include <sh.h>

void		usage_env()
{
	ft_putstr_fd("env [name=value ...]\n", STDERR_FILENO);
	ft_putstr_fd("env -i [name=value ...]\n", STDERR_FILENO);
	ft_putstr_fd("env -u [-u name]", STDERR_FILENO);
}

void		*error_env(void)
{
	ft_putstr_fd("env: invalid argument\n", STDERR_FILENO);
	var_return(1);
	return (NULL);
}