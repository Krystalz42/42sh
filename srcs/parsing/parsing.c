/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:11:28 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/13 11:58:00 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			special_logger(t_cmd *cmd);
void			token_logger(t_cmd *cmd);
void			list_logger(t_parsing *node);
void			split_logger(t_parsing *node);


/*
*************** PRIVATE ********************************************************
*/

static void		lexing(t_parsing **node, t_cmd *cmd)
{
	special_tokenisation(cmd);
	regular_tokenisation(cmd);
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
	special(node, "$?", var_return(-1));
	special(node, "$$", getpid());
	tilde(node);
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

	special_logger(cmd);
	token_logger(cmd);
	list_logger(node);
	split_logger(node);


	return (node);
}
