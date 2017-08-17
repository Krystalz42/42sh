/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:11:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/17 01:55:05 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			len_cmd(t_cmd **cmd)
{
	int		i;

	i = -1;
	while (++i >= 0 && (*cmd)->prev && (*cmd)->prev->c != 32 && (*cmd)->prev->c != 9)
		(*cmd) = (*cmd)->prev;
	return (i);
}

char		*list_to_str(t_cmd *cmd)
{
	int		i;
	int		len;
	char	*str;

	if (!(len = len_cmd(&cmd)))
		return (NULL);
	if (!(str = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = -1;
	while (++i < len)
	{
		str[i] = cmd->c;
		cmd = cmd->next;	
	}
	str[i] = '\0';
	return (str);
}

void		completion(t_read **read_std)
{
	char		*to_find;
	char		*tmp;

	to_find = list_to_str((*read_std)->cmd);
	if (to_find && (to_find[0] != '.' || to_find[0] != '/'))
	{
		tmp = ft_strjoin("./", to_find);
		ft_strdel(&to_find);
		complete_path(read_std, tmp);
		ft_strdel(&tmp);
	}
	else
	{
		complete_path(read_std, to_find);
		ft_strdel(&to_find);
	}
}
