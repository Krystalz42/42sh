/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:48:03 by aroulin           #+#    #+#             */
/*   Updated: 2017/12/13 15:48:54 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int				management_wildcard(char *data, char *tab_)
{
	if (*data != '\0' && *tab_ == '?')
		return (management_wildcard(data + 1, tab_ + 1));
	if (*data != '\0' && *tab_ == '*')
	{
		return (management_wildcard(data + 1, tab_)
				+ management_wildcard(data, tab_ + 1));
	}
	if (*data == '\0' && *tab_ == '*')
		return (management_wildcard(data, tab_ + 1));
	if (*data && *tab_ && *data == *tab_)
		return (management_wildcard(data + 1, tab_ + 1));
	if (*data == '\0' && *tab_ == '\0')
		return (1);
	return (0);
}

static inline void		delete_previous_path(t_read **read_std)
{
	(*read_std)->completion = 0;
	while ((*read_std)->cmd->prev && (*read_std)->cmd->prev->c != 32)
		key_del(read_std, DELETE_KEY);
	(*read_std)->completion = 2;
}

static inline void		add_command(t_read *read_std, t_path from, char *name)
{
	int			index;

	if ((from.to_comp[0] != '.' && name[0] == '.'))
		return ;
	index = 0;
	while (from.path && from.path[index])
	{
		if (ft_isprint(from.path[index]))
			key_print_fct(read_std->cmd, from.path[index]);
		index++;
	}
	index = 0;
	while (name && name[index])
	{
		if (ft_isprint(name[index]))
			key_print_fct(read_std->cmd, name[index]);
		index++;
	}
	if (index)
		key_print_fct(read_std->cmd, 32);
}

static inline int		check_compare(t_path from, char *name)
{
	if (from.to_comp == NULL && name[0] != '.')
		return (1);
	else if (from.to_comp && ft_strncmp(from.to_comp, name,
										ft_strlen(from.to_comp)) == 0)
		return (1);
	return (0);
}

void					create_comp(t_read **read_std, t_path from)
{
	DIR					*dir;
	struct dirent		*repo;
	int					index;

	index = 0;
	if ((dir = opendir((!from.path ? "." : from.path))))
	{
		while ((repo = readdir(dir)))
		{
			if ((ft_strchr(from.to_comp, '?') || ft_strchr(from.to_comp, '*'))
				&& management_wildcard(repo->d_name, from.to_comp))
			{
				(index == 0) ? delete_previous_path(read_std) : 0;
				index = -1;
				add_command(*read_std, from, repo->d_name);
			}
			else if ((check_compare(from, repo->d_name)))
				init_files(&((*read_std)->tab_->file), repo->d_name,
						repo->d_type, index++);
		}
		closedir(dir);
	}
	(*read_std)->tab_->element = index == -1 ? 0 : index;
}
