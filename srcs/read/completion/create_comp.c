/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tab_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:48:03 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/31 16:42:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>


static inline int	check_str(int value[2], char match[127], char *data, char *tab_)
{
	int i;

	if (value[0])
		if (value[1])
			return (!((*data) >= match[value[0] - 1] && (*data) <= match[value[0] + 1])
					? management_wildcard(data + 1, tab_ + 1) : 0);
		else
			return (((*data) >= match[value[0] - 1] && (*data) <= match[value[0] + 1])
					? management_wildcard(data + 1, tab_ + 1) : 0);
	else
	{
		i = -1;
		while (match[++i])
			if ((value[1] && *data != match[i]) || (!value[1] && *data == match[i]))
				return (management_wildcard(data + 1, tab_ + 1));
	}
	return (0);
}

static inline int	management_wildcard2(char *data, char *tab_)
{
	int		value[2];
	int		i;
	char 	match[127];

	value[0] = 0;
	i = -1;
	ft_bzero(match, 127);
	value[1] = ((*tab_) == '!') && (tab_++)? 1 : 0;
	while (i < 127 && (*tab_) != ']')
	{
		match[++i] = (*tab_);
		value[0] = ((*tab_) == '-') ? i : value[0];
		(tab_)++;
	}
	match[++i] = '\0';
	return (check_str(value, match, data, tab_));
}

static int 			management_wildcard(char *data, char *tab_)
{
	if (*data != '\0' && *tab_ == '[')
		return (management_wildcard2(data, tab_ + 1));
	if (*data != '\0' && *tab_ == '?')
		return (management_wildcard(data + 1, tab_ + 1));
	if (*data != '\0' && *tab_ == '*')
		return (management_wildcard(data + 1, tab_) + management_wildcard(data, tab_ + 1));
	if (*data == '\0' && *tab_ == '*')
		return (management_wildcard(data, tab_ + 1));
	if (*data && *tab_ && *data == *tab_)
		return (management_wildcard(data + 1, tab_ + 1));
	if (*data == '\0' && *tab_ == '\0')
		return (1);
	return (0);
}

void					create_comp(t_read **read_std, t_path f)
{
	DIR					*dir;
	struct dirent		*repo = 0;
	int					index;

	index = 0;
	if ((dir = opendir((!f.path ? "." : f.path))))
	{
		while ((repo = readdir(dir)))
			if ((!f.to_comp && repo->d_name[0] != '.') || (f.to_comp && (management_wildcard(repo->d_name, f.to_comp) || !ft_strncmp(f.to_comp, repo->d_name, ft_strlen(f.to_comp) - 1))))
			{
				init_files(&((*read_std)->tab_->file), repo->d_name,
						repo->d_type, index++);
			}
		closedir(dir);
	}
	(*read_std)->tab_->element = index;
}
