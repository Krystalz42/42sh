/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:11:28 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/01 13:20:46 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

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
	order(node);
	syntax(node);
	empty(node);
}

static void		expanding(t_parsing *node)
{
	alias(node);
	special(node, "$$", getpid());
	special(node, "$?", var_return(-1));
	tilde(node);
	variable(node);
	escape(node);
	split(node);
	argv(node);
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
	return (node);
}
