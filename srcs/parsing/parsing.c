/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:11:28 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/10 15:29:35 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			logger_token(t_cmd *cmd)
{
	int			fd = open("/tmp/token", O_RDWR | O_CREAT | O_TRUNC, 0644);

	while (cmd && cmd->c)
	{
		if (cmd->value == 1)
			dprintf(fd, " \e[34mchar: [%c]		value: [%d]\e[0m\n", cmd->c, cmd->value);
		else if (cmd->value == 2)
			dprintf(fd, " \e[32mchar: [%c]		value: [%d]\e[0m\n", cmd->c, cmd->value);
		cmd = cmd->next;
	}
	dprintf(fd, "------------------------------------------\n");
	close(fd);
}

void			logger_list(t_parsing *node)
{
	int			fd = open("/tmp/list", O_RDWR | O_CREAT | O_TRUNC, 0644);

	while (node)
	{
		if (node->priority == SYNTAX_ERR)
			dprintf(fd, "\e[31mstr: [%s]	value: [%d]		prio: [%d]\e[0m\n", node->input, node->value, node->priority);
		else if (node->priority == 5)
			dprintf(fd, "\e[34mstr: [%s]	value: [%d]		prio: [%d]\e[0m\n", node->input, node->value, node->priority);
		else
			dprintf(fd, "\e[32mstr: [%s]	value: [%d]		prio: [%d]\e[0m\n", node->input, node->value, node->priority);
		node = node->next;
	}
	dprintf(fd, "------------------------------------------\n");
	close(fd);
}

/*
*************** PRIVATE ********************************************************
*/

static void		lexing(t_parsing **node, t_cmd *cmd)
{
	tokenisation(cmd);
	lexer(cmd, node);
	recognition(*node);
}

static void		parser(t_parsing **node)
{
	empty(node);
	order(node);
	syntax(node);
}

static void		expanding(t_parsing *node)
{
	tilde(node);
	//variable(node);
	// backslash(node);
	split(node);
}


/*
*************** PUBLIC *********************************************************
*/

t_parsing		*parsing(t_cmd *cmd)
{
	t_parsing	*node;

	node = NULL;
	lexing(&node, cmd);
	parser(&node);
	expanding(node);

	logger_token(cmd);
	logger_list(node);

	return (node);
}
