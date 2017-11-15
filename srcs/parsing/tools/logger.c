/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:43:31 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/15 13:59:50 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void			special_logger(t_cmd *cmd)
{
	int			fd = -1;
	fd = open("/tmp/.special", O_RDWR | O_CREAT | O_TRUNC, 0644);
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
	dprintf(fd, "-----------------------------------------\n");
	close(fd);
}

void			token_logger(t_cmd *cmd)
{
	int			fd = -1;
	fd = open("/tmp/.token", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (cmd && cmd->c)
	{
		if (cmd->value == TOKEN)
			dprintf(fd, "\e[34mchar: [%c]		value: [%d]\e[0m\n", cmd->c, cmd->value);
		else
			dprintf(fd, "\e[31mchar: [%c]		value: [%d]\e[0m\n", cmd->c, cmd->value);
		cmd = cmd->next;
	}
	dprintf(fd, "\n");
	dprintf(fd, "-----------------------------------------\n");
	close(fd);
}

void			list_logger(t_parsing *node)
{
	uint8_t		rounds = 0;
	int			fd = -1;
	fd = open("/tmp/.list", O_RDWR | O_CREAT | O_TRUNC, 0644);
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
	dprintf(fd, "-----------------------------------------\n");
	close(fd);
}

void			split_logger(t_parsing *node)
{
	size_t		index;
	uint8_t		rounds = 0;
	int			fd = -1;
	fd = open("/tmp/.split", O_RDWR | O_CREAT | O_TRUNC, 0644);
	while (node)
	{
		if (!rounds)
		{
			index = 0;
			while (node->command && node->command[index])
				dprintf(fd, "\e[34mstr: [%s]\e[0m\n", node->command[index++]);
		}
		else
			dprintf(fd, "\e[31mstr: [%s]\e[0m\n", node->command[0]);
		rounds = rounds ? 0 : 1;
		node = node->next;
	}
	dprintf(fd, "\n");
	dprintf(fd, "-----------------------------------------\n");
	close(fd);
}
