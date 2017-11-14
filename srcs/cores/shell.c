/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:11:34 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/14 16:32:03 by jle-quel         ###   ########.fr       */
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

void			stdel(t_parsing **node)
{
	if ((*node)->env_option)
		ft_memdel_tab(&(*node)->env);
	ft_memdel_tab(&(*node)->command);
	ft_strdel(&(*node)->input);
	ft_strdel(&(*node)->heredoc);
	ft_memdel((void **)&(*node));
	(*node) = NULL;
}

void		free_node(t_node **node)
{
	if (*node)
	{
		if ((*node)->left)
			free_node(&((*node)->left));
		if ((*node)->right)
			free_node(&((*node)->right));
		stdel(&(*node)->content);
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
	while (0x2A)
	{
		memdel_cmd(&input);
		free_node(&tree);
		log_success("----------------- Welcome to the new command ! ----------------");
		if ((input = read_stdin(DEFAULT)) == NULL)
		{
			log_error("To cont %d", input ? 1 : 0);
			continue ;
		}
		log_error("%d", input ? 1 : 0);
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
