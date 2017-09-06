/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 16:11:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 13:08:44 by aroulin          ###   ########.fr       */
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

char		*list_to_str(t_read **read_std, t_cmd *cmd)
{
	int		i;
	int		len;
	char	*str;

	if (!(len = len_cmd(&cmd)))
		return (NULL);
	if (len == 1 && cmd && cmd->c == '.' && key_print_(read_std, '/'))
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

char		*get_last_word(char *path)
{
	int		i;
	int		s;
	char	*tmp;

	s = -1;
	tmp = NULL;
	if ((i = -1) && path)
	{
		while (path[++i])
			if (path[i] == '/')
				s = i;
		if (i - s - 1 > 0)
		{
			tmp = ft_strdup(path + s + 1);
			ft_bzero(path + s + 1, i - s);
		}
	}
	return (tmp);
}

void		completion(t_read **read_std)
{
	t_path		f;
	char 		*tmp;

	f.to_comp = NULL;
	f.path = list_to_str(read_std, (*read_std)->cmd);
	STR_FD(f.path, fdb); CHAR_FD(10,fdb);
	if (f.path && (f.path[0] != '.' && f.path[0] != '/'))
	{
		tmp = ft_strjoin("./", f.path);
		ft_strdel(&f.path);
		f.path = tmp;
	}
	f.to_comp = get_last_word(f.path);
	complete_path(read_std, f);
	ft_memdel((void **)&(f.path));
	ft_memdel((void **)&(f.to_comp));
}
