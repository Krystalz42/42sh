//
// Created by Alexandre ROULIN on 12/16/17.
//

#include <sh.h>

static void		jobs_do_string(t_parsing *node, char *heredoc)
{
	int					fildes;
	char				*temp;

	temp = ft_itoa(time(NULL));
	node->heredoc = ft_strjoin("/tmp/", temp);
	fildes = open(node->heredoc, O_WRONLY | O_CREAT, 0644);
	ft_memdel((void **)&temp);
	ft_putendl_fd(heredoc, fildes);
	close(fildes);
}

void			do_string(t_parsing *node)
{
	if (node)
	{
		jobs_do_string(node, node->next->command[0]);
		do_string(node->next->next);
	}
}