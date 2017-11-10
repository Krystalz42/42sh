/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:17:08 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/10 15:27:49 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"


/*
*************** TOOLS **********************************************************
*/

static char		*get_variable(char *str)
{
	size_t		index;
	char		*new;

	index = 0;
	while (str && str[index])
	{
		if (str[index] == '\"' || str[index] == ' ' || str[index] == '/')
			break ;
		index++;
	}
	new = index ? ft_strsub(str, 0, index) : NULL;
	return (new);
}

/*static void		populate(char *new, char *str, char *variable, size_t length)*/
/*{*/
	/*size_t		index;*/
	/*char		*temp;*/

	/*index = 0;*/
	/*temp = str + length + 5;*/
	/*while (str && *str && length--)*/
		/*new[index++] = *str++;*/
	/*while (variable && *variable)*/
		/*new[index++] = *variable++;*/
	/*while (temp && *temp)*/
		/*new[index++] = *temp++;*/
/*}*/

/*
*************** PRIVATE ********************************************************
*/

static void		expansion(char **str, size_t index)
{
	char		*temp;
	char		*memory;
	char		*variable;

	temp = get_variable(*str + (index + 1));
	memory = temp;
	temp = ft_strjoin(temp, "=");
	ft_memdel((void **)&memory);

	variable = my_getenv(temp);
	ft_putendl(variable);
	ft_putendl(temp);
	exit(1);
}

/*
*************** PUBLIC *****************************************************
*/

void			variable(t_parsing *node)
{
	size_t		index;
	uint8_t		status;
	t_parsing	*temp;

	status = DEFAULT;
	temp = node;
	while (node)
	{
		index = 0;
		while (node->input && node->input[index])
		{
			chk_quote(node->input[index], &status);
			if (status & (DEFAULT | DQUOTE) && node->input[index] == '$')
				expansion(&node->input, index);
			index++;
		}
		node = node->next;
	}
}
