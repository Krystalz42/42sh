/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:42:40 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 16:43:00 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static void		memdel_parsing(t_parsing **node)
{
	if ((*node)->env_option)
		ft_memdel_tab(&(*node)->env);
	ft_memdel_tab(&(*node)->command);
	ft_strdel(&(*node)->input);
	ft_strdel(&(*node)->heredoc);
	ft_memdel((void **)&(*node));
	(*node) = NULL;
}

void			memdel_node(t_node **node)
{
	if (*node)
	{
		if ((*node)->left)
			memdel_node(&((*node)->left));
		if ((*node)->right)
			memdel_node(&((*node)->right));
		memdel_parsing(&(*node)->content);
		ft_memdel((void **)node);
	}
}
