/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:11:34 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:11:36 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char *test(t_cmd *cmd)
{
	t_cmd	*temp;
	int 	len;
	char *str;

	temp = cmd;
	len = 0;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	str = (char *)ft_memalloc(len);
	len = 0;
	while (cmd)
	{
		str[len] = cmd->c;
		cmd = cmd->next;
		len++;
	}
	return (str);
}

void place_pseudo_prio(t_parsing *p)
{
	char *d[] = {";", "|", "||", "&&", NULL};
	int 	index = 0;
	p->priority = PRIO_COMMAND;
	while (p->next)
	{
		p->priority = PRIO_COMMAND;
		p = p->next;
		index = 0;
		while (d[index])
		{
			if (ft_strcmp(p->input, d[index]) == 0)
			{
				p->value = ((index == 0)) ? VALUE_SEMI_COLON : p->value;
				p->value = ((index == 1)) ? VALUE_PIPELINE : p->value;
				p->priority = (index == 0) ? 1 : p->priority;
				p->priority = (index == 1) ? 3 : p->priority;
				p->priority = (index == 2) ? 2 : p->priority;
				p->priority = (index == 3) ? 2 : p->priority;

			}
			index++;
		}
		p = p->next;
		p->priority = PRIO_COMMAND;
	}
}

void	print_tree(t_node *tree, int stage)
{
	if (tree)
	{
		log_warn("A l'etage [%d], > [%s] of [%d]", stage, tree->content->input, tree->content->priority);
		print_tree(tree->left, stage + 1);
		print_tree(tree->right, stage + 1);
	}
}

void c(t_parsing *parse_struct)
{
	while (parse_struct)
	{
		parse_struct->command = ft_strsplit(parse_struct->input, 32);
		parse_struct = parse_struct->next;
	}
}

void	free_node(t_node *node)
{
	if (node)
	{
		if (node->left)
			free_node(node->left);
		if (node->right)
			free_node(node->right);
		lstdel(&node->content);
		ft_memdel((void **)&node);
	}
}

int		shell(void)
{
	t_cmd		*input;
	t_parsing	*parse_struct;
	char 		*input_string;
	t_node		*tree;

	add_hash("ls", "/bin/ls", 1);
	add_hash("cat", "/bin/cat", 1);
	add_hash("wc", "/usr/bin/wc", 1);
	input = NULL;
	input_string = NULL;
	while (42)
	{
		parse_struct = NULL;
		ft_strdel(&input_string);
		memdel_cmd(&input);

		if (parse_struct == NULL)
			log_fatal("gg");
		if ((input = read_stdin(DEFAULT)) == NULL)
			continue ;

		input_string = test(first_cmd(input, 1));
		if ((parse_struct = parsing(input_string)) == NULL)
			continue ;

		c(parse_struct);
		place_pseudo_prio(parse_struct);
		tree = create_binary_tree(parse_struct, NULL, PRIO_SEPARATOR);
//		print_tree(tree, 0);
		execute_node(tree, FORK | FOREGROUND);
		free_node(tree);
	}
}
