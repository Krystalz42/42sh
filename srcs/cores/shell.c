/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:11:34 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/20 02:01:31 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		shell(void)
{
	t_cmd		*input;
	t_parsing	*parse_struct;
	t_node		*tree;

	input = NULL;
	tree = NULL;
	while (0x2A)
	{
		memdel_cmd(&input);
		memdel_node(&tree);
		dprintf(fd_log, "----------------------------------------------------\n");
		dprintf(fd_log, "--------------- New command from [%s]---------------\n", __FILENAME__);
		dprintf(fd_log, "----------------------------------------------------\n");
		if ((input = read_stdin(DEFAULT)) == NULL)
			continue ;
		if ((parse_struct = parsing(input)) == NULL)
			continue ;
		if (!(tree = create_binary_tree(parse_struct, NULL, PRIO_SEPARATOR)))
			continue ;
		check_tree_path(tree);
		if (signal_reception(-1) == SIGINT)
			continue ;
		execute_node(tree, NULL, FORK | FOREGROUND);
		cursor_column(1);
	}
	return (0);
}
