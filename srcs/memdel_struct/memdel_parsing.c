/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memdel_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:40:49 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/20 14:40:52 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		memdel_parsing(t_parsing **node)
{
	t_parsing		*to_kill;

	while (*node)
	{
		to_kill = *node;
		*node = (*node)->next;
		ft_memdel((void **)&to_kill->input);
		ft_memdel((void **)&to_kill->heredoc);
		if (to_kill->env_option)
			ft_memdel_tab(&to_kill->env);
		ft_memdel_tab(&to_kill->command);
		ft_memdel((void **)&to_kill);
	}
	*node = NULL;
}
