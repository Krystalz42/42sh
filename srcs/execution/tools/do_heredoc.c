/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:12:05 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 01:19:34 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void		jobs_do_heredoc(t_node *node, char **heredoc)
{
	int					fildes;
	char				*temp;

	temp = ft_itoa(time(NULL));
	node->content->heredoc = ft_strjoin("/tmp/", temp);
	fildes = open(node->content->heredoc, O_WRONLY | O_CREAT, 0644);
	ft_memdel((void **)&temp);
	ft_putstrtab_fd(heredoc, 10, fildes);
	close(fildes);
}

void			do_heredoc(t_node *node)
{
	t_cmd				*cmd;
	char				**heredoc;

	heredoc = NULL;
	while (0x2A)
	{
		cmd = first_cmd(read_stdin(HEREDOC), 1);
		if (signal_reception(-1) == SIGINT)
			break ;
		else if (compare_heredoc(cmd, node->right->content->command[0]) == 0 || signal_reception(-1) == 1)
		{
			jobs_do_heredoc(node, heredoc);
			memdel_cmd(&cmd);
			break ;
		}
		else
		{
			heredoc = build_table(heredoc, convert_to_str(cmd));
			memdel_cmd(&cmd);
		}
	}
	ft_memdel_tab(&heredoc);
}
