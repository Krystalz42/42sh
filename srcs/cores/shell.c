/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:11:34 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/09 20:07:30 by jle-quel         ###   ########.fr       */
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

void		free_node(t_node **node)
{
	if (*node)
	{
		if ((*node)->left)
			free_node(&((*node)->left));
		if ((*node)->right)
			free_node(&((*node)->right));
		lstdel(&(*node)->content);
 		ft_memdel((void **)node);
 	}
}

int		shell(void)
{
	t_cmd		*input;
	t_parsing	*parse_struct;
	t_node		*tree;

	input = NULL;
	parse_struct = NULL;
	tree = NULL;
	while (42)
	{
		memdel_cmd(&input);
		if ((input = read_stdin(DEFAULT)) == NULL)
			continue ;


		if ((parse_struct = parsing(first_cmd(input, 1))) == NULL)
			continue ;

		if ((tree = create_binary_tree(parse_struct, NULL, PRIO_SEPARATOR)) == NULL)
			continue ;
		print_tree(tree, 0);
		check_tree_path(tree);
		execute_node(tree, NULL, FORK | FOREGROUND);
		cursor_column(1);
		free_node(&tree);
	}
}
