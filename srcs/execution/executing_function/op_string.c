//
// Created by Alexandre ROULIN on 12/16/17.
//

#include <sh.h>

void				op_string(t_parsing *node)
{
	int			std;
	int			std_in;

	std_in = STDIN_FILENO;
	if (ft_isdigit(node->command[0][0]))
		std_in = ft_atoi(node->command[0]);
	if ((std = open(node->heredoc, O_RDWR)) == -1)
;	if (dup2(std, std_in) == -1)
		error_msg(S42H, BAD_FD, NULL);
	close(std);
}
