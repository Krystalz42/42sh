/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:04:51 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 15:05:13 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_parsing	*create_binary_tree(t_parsing *list, t_parsing *compare, int priority)
{
	t_parsing		*keep;
	t_parsing		*temp;

	keep = NULL;
	temp = list;
	if (priority == PRIO_REDIR || list == NULL)
		return (NULL);
	while (temp != compare)
	{
		if (temp->priority == priority)
			keep = temp;
		temp = temp->next;
	}
	if (keep)
	{
		keep->left = create_binary_tree(list, keep, priority);
		keep->right = create_binary_tree(keep->next, compare, priority + 1);
		return (keep);
	}
	else
		return (create_binary_tree(list, compare, priority + 1));
}
