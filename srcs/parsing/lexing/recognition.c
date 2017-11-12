/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recognition.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:08:58 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/12 20:33:38 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

const t_lexing	g_operaters[] =
{
	(t_lexing){";", VALUE_SEMI_COLON, PRIO_SEPARATOR},
	(t_lexing){"&&", VALUE_AND_IF, PRIO_CMD_AND_OR},
	(t_lexing){"||", VALUE_OR_IF, PRIO_CMD_AND_OR},
	(t_lexing){"|", VALUE_PIPELINE, PRIO_PIPE},
	(t_lexing){"&", VALUE_AMPERSAND, PRIO_SEPARATOR},
	(t_lexing){"<<", VALUE_DLESS, PRIO_REDIR},
	(t_lexing){">>", VALUE_DGREAT, PRIO_REDIR},
	(t_lexing){">&", VALUE_GREAT_AND, PRIO_REDIR},
	(t_lexing){"<", VALUE_LESS, PRIO_REDIR},
	(t_lexing){">", VALUE_GREAT, PRIO_REDIR},
	(t_lexing){NULL, SYNTAX_ERR, SYNTAX_ERR}
};

/*
*************** PRIVATE ********************************************************
*/

static char		*get_str_without_digit(char *str)
{
	size_t		index;
	char		*new;

	new = NULL;
	if (str)
	{
		index = 0;
		new = ft_memalloc(ft_strlen(str) + 1);
		while (*(str))
		{
			if (!ft_isdigit(*(str)))
				new[index++] = *(str);
			str++;
		}
	}
	return (new);
}

static bool		chk_operaters(char *str, char *search)
{
	if (str)
	{
		while (*(search))
		{
			if (ft_strchr(str, *(search)))
				return (true);
			search++;
		}
	}
	return (false);
}

static void		get_info(char *str, t_parsing *node)
{
	size_t		index;

	if (str)
	{
		index = 0;
		while (index < 10)
		{
			if (!ft_strcmp(str, g_operaters[index].str))
				break ;
			index++;
		}
		node->value = g_operaters[index].value;
		node->priority = g_operaters[index].priority;
	}
}

/*
*************** PUBLIC *********************************************************
*/

void			recognition(t_parsing *node)
{
	char		*temp;

	while (node)
	{
		temp = get_str_without_digit(node->input);
		if (chk_operaters(temp, ";|<>&") && !chk_operaters(temp, "\\\'\""))
			get_info(temp, node);
		else
		{
			node->value = VALUE_COMMAND;
			node->priority = PRIO_COMMAND;
		}
		ft_memdel((void **)&temp);
		node = node->next;
	}
}
