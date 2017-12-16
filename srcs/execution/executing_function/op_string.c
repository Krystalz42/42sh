//
// Created by Alexandre ROULIN on 12/16/17.
//

#include <sh.h>

int				op_string(t_parsing *node)
{
	int			std_out;
	
	if ((std_out = open(node->heredoc, O_RDONLY)) == -1)
		exit(1);
	if (dup2(std_out, STDIN_FILENO) == -1)
		return (error_msg(S42H, BAD_FD, NULL) - 1);
	return (1);
}
