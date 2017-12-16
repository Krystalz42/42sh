/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:11:34 by aroulin           #+#    #+#             */
/*   Updated: 2017/12/15 17:50:22 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		shell(void)
{
	t_cmd		*input;
	t_parsing	*parse_struct;
	t_parsing	*tree;

	input = NULL;
	parse_struct = NULL;
	while (0x2A)
	{
		memdel_cmd(&input);
		memdel_parsing(&parse_struct);
		if ((input = read_input(DEFAULT)) == NULL)
			continue ;
		if ((parse_struct = parsing(input)) == NULL)
			continue ;
		if (!(tree = create_binary_tree(parse_struct, NULL, PRIO_SEPARATOR)))
			continue ;
		check_tree_path(tree);
		if (signal_reception(-1) == SIGINT)
			continue ;
		signal(SIGCHLD, SIG_DFL);
		execute_node(tree, NULL, FORK | FOREGROUND);
		signal(SIGCHLD, &handler_sigchld);
		cursor_column(1);
	}
}
