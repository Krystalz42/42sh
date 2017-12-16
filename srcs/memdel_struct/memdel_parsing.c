//
// Created by Alexandre ROULIN on 12/16/17.
//

#include <sh.h>

void		memdel_parsing(t_parsing **node)
{
	t_parsing		*to_kill;

	while (*node)
	{
		to_kill = *node;
		*node = (*node)->next;
		ft_memdel((void **)&to_kill->heredoc);
		if (to_kill->env_option)
			ft_memdel_tab(&to_kill->env);
		ft_memdel_tab(&to_kill->command);
	}
	*node = NULL;
}