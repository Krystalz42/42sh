/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:11:34 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/14 19:13:55 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void	print_tree(t_node *tree, int stage)
{
	if (tree)
	{
		print_tree(tree->left, stage + 1);
		log_warn("A l'etage [%d], > [%s] of [%d]", stage, tree->content->input, tree->content->priority);
		print_tree(tree->right, stage + 1);
	}
}

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
		log_success(" Welcome to the new command !");
		if ((input = read_stdin(DEFAULT)) == NULL)
			continue ;
		if ((parse_struct = parsing(input)) == NULL)
			continue ;
		if ((tree = create_binary_tree(parse_struct, NULL, PRIO_SEPARATOR)) == NULL)
			continue ;
		check_tree_path(tree);
		execute_node(tree, NULL, FORK | FOREGROUND);
		cursor_column(1);
	}
	return (0);
}
