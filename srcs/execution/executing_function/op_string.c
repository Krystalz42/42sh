//
// Created by Alexandre ROULIN on 12/16/17.
//

#include <sh.h>

int				op_string(t_parsing *node)
{
	int			std;
	int			std_in;

	std_in = STDIN_FILENO;
	if (ft_isdigit(node->command[0][0]))
		std_in = ft_atoi(node->command[0]);
	if ((std = open(node->heredoc, O_RDWR)) == -1)
		return (0);
	if (dup2(std, std_in) == -1)
		return (error_msg(S42H, BAD_FD, NULL) - 1);
	close(std);
	return (1);
}
