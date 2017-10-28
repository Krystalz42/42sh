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

static int				management_wildcard(char *data, char *tab_)
{
	if (*data != '\0' && *tab_ == '?')
		return (management_wildcard(data + 1, tab_ + 1));
	if (*data != '\0' && *tab_ == '*')
		return (management_wildcard(data + 1, tab_) + \
				management_wildcard(data, tab_ + 1));
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
	struct dirent		*repo;
	int					index;

	index = 0;
	if ((dir = opendir((!f.path ? "." : f.path))))
	{
		while ((repo = readdir(dir)))
			if ((!f.to_comp && repo->d_name[0] != '.') ||
					(f.to_comp && (management_wildcard(repo->d_name, f.to_comp)
			|| !ft_strncmp(f.to_comp, repo->d_name, ft_strlen(f.to_comp)))))
			{
				init_files(&((*read_std)->tab_->file), repo->d_name,
						repo->d_type, index++);
			}
		closedir(dir);
	}
	(*read_std)->tab_->element = index;
}
