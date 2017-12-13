/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 12:52:30 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/13 18:21:30 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static char		*populate(char *str, char *home, size_t length, char *original)
{
	size_t		index;
	char		*new;
	char		*temp;

	index = 0;
	new = (char *)ft_memalloc(sizeof(char) *
										(ft_strlen(str) + ft_strlen(home) + 1));
	temp = str + (length + ft_strlen(original));
	while (str && *str && length--)
		new[index++] = *str++;
	while (home && *home)
		new[index++] = *home++;
	while (temp && *temp)
		new[index++] = *temp++;
	return (new);
}

static void		expansion(char **str, size_t index)
{
	char		**temp;
	char		*alias;
	char		*new;

	temp = ft_strsplit(*str + index, ' ');
	if (temp && temp[0] && (alias = alias_exist(temp[0])))
	{
		new = populate(*str, alias, index, temp[0]);
		ft_memdel((void **)str);
		arraydel(&temp);
		*str = new;
	}
	arraydel(&temp);
}


/*
*************** PUBLIC *********************************************************
*/

void			alias(t_parsing *node)
{
	size_t		index;
	t_parsing	*temp;

	temp = node;
	while (node)
	{
		index = 0;
		while (node->input && node->input[index])
		{
			if (node->input[index] == '\\')
				index += 2;
			else if (node->input[index] == '\'')
				index += skip_to_occurence(node->input + index, '\'');
			else if (node->input[index] == '\"')
				index += skip_to_occurence(node->input + index, '\"');
			else if (node->input[index] == ' ')
				index++;
			else
			{
				expansion(&node->input, index);
				return ;
			}
		}
		node = node->next;
	}
}
