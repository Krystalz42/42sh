/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:09:52 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 15:09:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					compare_heredoc(t_cmd *cmd, char *string)
{
	int			index;

	index = 0;
	if (cmd)
	{
		while (cmd->c && string[index])
		{
			if (cmd->c != string[index])
				return (cmd->c - string[index]);
			cmd = cmd->next;
			index++;
		}
		return (cmd->c - string[index]);
	}
	return (-1);
}

char				*convert_to_str(t_cmd *cmd)
{
	t_cmd		*temp;
	size_t		len;
	char		*string;

	temp = cmd;
	len = 0;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	string = (char *)ft_memalloc(sizeof(char) * (len));
	len = 0;
	while (cmd->c)
	{
		string[len++] = cmd->c;
		cmd = cmd->next;
	}
	string[len] = '\0';
	return (string);
}

char				**build_table(char **heredoc, char *str)
{
	char		**temp;
	size_t		len;

	len = 0;
	temp = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(heredoc) + 2));
	if (heredoc)
	{
		while (heredoc[len])
		{
			temp[len] = heredoc[len];
			len++;
		}
		free((void *)heredoc);
	}
	temp[len++] = str;
	temp[len] = NULL;
	return (temp);
}
