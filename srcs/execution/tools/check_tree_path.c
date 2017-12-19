/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tree_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:11:11 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 16:05:13 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			manage_redir(t_parsing *node)
{
	if (node)
	{
		if (node->value == VALUE_DLESS)
			do_heredoc(node);
		if (node->value == VALUE_STRING)
			do_string(node);
		manage_redir(node->next->next);
	}
}

void			check_tree_path(t_parsing *node)
{
	if (signal_reception(-1) == SIGINT)
		return ;
	if (node)
	{
		if (node->value == VALUE_COMMAND)
		{
			if (check_if_builtin(node, DONT_EXECUTE) == -1)
				if (ft_strchr(node->command[0], '/') == NULL)
					if ((looking_for_path(&node->command[0])) == 0)
						collect_path(&node->command[0]);
			manage_redir(node->next);
		}
		check_tree_path(node->left);
		check_tree_path(node->right);
	}
}
