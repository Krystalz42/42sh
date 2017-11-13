/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:43:31 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/13 20:03:08 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			special_logger(t_cmd *cmd)
{
	int			fd = open("/tmp/.special", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (cmd && cmd->c)
	{
		if (cmd->status == DEFAULT)
			dprintf(fd, "\e[34mchar: [%c]		status: [%d]\e[0m\n", cmd->c, cmd->status);
		else if (cmd->status == SINGLE_QUOTE)
			dprintf(fd, "\e[31mchar: [%c]		status: [%d]\e[0m\n", cmd->c, cmd->status);
		else if (cmd->status == DOUBLE_QUOTE)
			dprintf(fd, "\e[32mchar: [%c]		status: [%d]\e[0m\n", cmd->c, cmd->status);
		else if (cmd->status == BACKSLASH)
			dprintf(fd, "\e[33mchar: [%c]		status: [%d]\e[0m\n", cmd->c, cmd->status);
		cmd = cmd->next;
	}
	dprintf(fd, "\n");
}

void			token_logger(t_cmd *cmd)
{
	int			fd = open("/tmp/.token", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (cmd && cmd->c)
	{
		if (cmd->value == TOKEN)
			dprintf(fd, "\e[34mchar: [%c]		value: [%d]\e[0m\n", cmd->c, cmd->value);
		else
			dprintf(fd, "\e[31mchar: [%c]		value: [%d]\e[0m\n", cmd->c, cmd->value);
		cmd = cmd->next;
	}
	dprintf(fd, "\n");
}

void			list_logger(t_parsing *node)
{
	uint8_t		rounds = 0;
	int			fd = open("/tmp/.list", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (node)
	{
		if (!rounds)
			dprintf(fd, "\e[34mstr: [%s]	value: [%d]		priority: [%d]\e[0m\n", node->input, node->value, node->priority);
		else
			dprintf(fd, "\e[31mstr: [%s]	value: [%d]		priority: [%d]\e[0m\n", node->input, node->value, node->priority);
		rounds = rounds ? 0 : 1;
		node = node->next;
	}
	dprintf(fd, "\n");
}

void			split_logger(t_parsing *node)
{
	uint8_t		rounds = 0;
	int			fd = open("/tmp/.split", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (node)
	{
		if (!rounds)
		{
			while (*node->command)
				dprintf(fd, "\e[34mstr: [%s]\e[0m\n", *node->command++);
		}
		else
			dprintf(fd, "\e[31mstr: [%s]\e[0m\n", *node->command);
		dprintf(fd, "\n");
		rounds = rounds ? 0 : 1;
		node = node->next;
	}
}
