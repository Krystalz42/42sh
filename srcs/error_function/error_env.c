//
// Created by Alexandre ROULIN on 10/14/17.
//

#include <sh.h>



void		*error_env(void)
{
	ft_putstr_fd("env: invalid argument\n", STDERR_FILENO);
	var_return(1);
	return (NULL);
}