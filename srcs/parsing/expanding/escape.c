/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:27:36 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/15 16:37:57 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

const t_esc		g_esc[] =
{
	(t_esc){"\\a", "\007"},
	(t_esc){"\\b", "\010"},
	(t_esc){"\\f", "\014"},
	(t_esc){"\\n", "\012"},
	(t_esc){"\\r", "\015"},
	(t_esc){"\\t", "\011"},
	(t_esc){"\\v", "\013"}
};

/*
*************** TOOLS **********************************************************
*/

static void		populate(char *new, char *str, char *variable, size_t length)
{
	size_t		index;
	char		*temp;

	index = 0;
	temp = str + (length + 2);
	while (str && *str && length--)
		new[index++] = *str++;
	while (variable && *variable)
		new[index++] = *variable++;
	while (temp && *temp)
		new[index++] = *temp++;
}

static char		*get_variable(char *str)
{
	short		index;
	char		*variable;

	index = 0;
	variable = NULL;
	while (index < 7)
	{
		if (!ft_strncmp(str, g_esc[index].esc, 2))
		{
			variable = g_esc[index].to_esc;
			break ;
		}
		index++;
	}
	return (variable);
}

/*
*************** PRIVATE ********************************************************
*/

static void		expansion(char **str, size_t index, char *variable)
{
	char	*new;

	new = (char *)ft_memalloc(sizeof(char) * (ft_strlen(variable) + ft_strlen(*str) + 1));
	populate(new, *str, variable, index);
	ft_memdel((void **)str);
	*str = new;
}

/*
*************** PUBLIC *********************************************************
*/

void			escape(t_parsing *node)
{
	size_t		index;
	uint8_t		occurence;
	uint8_t		status;
	t_parsing	*temp;
	char		*variable;

	occurence = 0;
	status = DEFAULT;
	temp = node;
	while (node)
	{
		index = 0;
		while (node->input && node->input[index])
		{
			if (status & DOUBLE_QUOTE && (variable = get_variable(node->input + index)))
			{
				expansion(&node->input, index, variable);
				escape(temp);
			}
			else if (node->input[index] == '\\')
				index += 2;
			else if (node->input[index] == '\'')
				index += skip_to_occurence(node->input + index, '\'');
			else
			{
				chk_quote(node->input[index], &status);
				index += 1;
			}
		}
		node = node->next;
	}
}
