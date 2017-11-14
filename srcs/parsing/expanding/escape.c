/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:27:36 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/14 17:50:24 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

// const t_esc		g_esc[] =
// {
// 	(t_esc){"\\a", "\007"},
// 	(t_esc){"\\b", "\008"},
// 	(t_esc){"\\f", "\012"},
// 	(t_esc){"\\n", "\010"},
// 	(t_esc){"\\r", "\013"},
// 	(t_esc){"\\t", "\009"},
// 	(t_esc){"\\v", "\011"}
// };
//
// /*
// *************** TOOLS **********************************************************
// */
//
// static void		populate(char *new, char *str, char *variable, size_t length)
// {
// 	size_t		index;
// 	char		*temp;
//
// 	index = 0;
// 	temp = str + (length + 2);
// 	while (str && *str && length--)
// 		new[index++] = *str++;
// 	while (variable && *variable)
// 		new[index++] = *variable++;
// 	while (temp && *temp)
// 		new[index++] = *temp++;
// }
//
// static char		*get_variable(char *str)
// {
// 	short		index;
// 	char		*variable;
//
// 	index = 0;
// 	variable = NULL;
// 	while (index < 7)
// 	{
// 		if (!ft_strncmp(str, g_esc[index].esc, 2))
// 		{
// 			variable = g_esc[index].to_esc;
// 			break ;
// 		}
// 		index++;
// 	}
// 	return (variable);
// }
//
// /*
// *************** PRIVATE ********************************************************
// */
//
// size_t			skip_to_occurence(char *str, char c)
// {
// 	size_t		index;
// 	uint8_t		occurence;
//
// 	index = 0;
// 	occurence = 0;
// 	while (str && str[index] && occurence < 2)
// 	{
// 		occurence += str[index] == c ? 1 : 0;
// 		index++;
// 	}
// 	return (index);
// }
//
// static bool		expansion(char **str, size_t index)
// {
// 	char	*variable;
// 	char	*new;
//
// 	if ((variable = get_variable(*str + index)))
// 	{
// 		new = (char *)ft_memalloc(sizeof(char) * (ft_strlen(variable) + ft_strlen(*str) + 1));
// 		populate(new, *str, variable, index);
// 		ft_memdel((void **)str);
// 		*str = new;
// 		return (true);
// 	}
// 	return (false);
// }
//
// /*
// *************** PUBLIC *********************************************************
// */
//
// void			escape(t_parsing *node)
// {
//
// 	// size_t		index;
// 	// t_parsing	*temp;
// 	//
// 	// temp = node;
// 	// while (node)
// 	// {
// 	// 	index = 0;
// 	// 	while (node->input && node->input[index])
// 	// 	{
// 	// 		if (node->input[index] == '\\')
// 	// 			index += 2;
// 	// 		else if (node->input[index] == '\'')
// 	// 			index += skip_to_occurence(node->input + index, '\'');
// 	// 		else if (node->input[index] == '\"')
// 	// 		{
// 	// 			get_expand(node->input + index);
// 	// 			if (expansion(&node->input, index))
// 	// 				escape(temp);
// 	// 		}
// 	// 		else
// 	// 			index += 1;
// 	// 	}
// 	// 	node = node->next;
// 	// }
// }
