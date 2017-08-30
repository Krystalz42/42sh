/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:48:03 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 20:45:37 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			managementWildcard(char *data, char *comp)
{
	if (*data != '\0' && *comp == '*')
		return (managementWildcard(data + 1, comp) + managementWildcard(data, comp + 1));
	if (*data == '\0' && *comp == '*')
		return (managementWildcard(data, comp + 1));
	if (*data && *comp && *data == *comp)
		return (managementWildcard(data + 1, comp + 1));
	if (*data == '\0' && *comp == '\0')
		return (1);
	return (0);
}

void		create_comp(t_read **read_std, t_path f)
{
	DIR					*dir;
	struct dirent		*repo = 0;
	int					index;

	index = 0;
	if ((dir = opendir((!f.path ? "." : f.path))))
	{
		while ((repo = readdir(dir)))
			if ((!f.to_comp && repo->d_name[0] != '.') || (f.to_comp && (managementWildcard(repo->d_name, f.to_comp) || !ft_strncmp(f.to_comp, repo->d_name, ft_strlen(f.to_comp) - 1))))
			{
				init_files(&((*read_std)->comp->tab_->file), repo->d_name,
						repo->d_type, index++);
			}
		closedir(dir);
	}
	(*read_std)->comp->tab_->element = index;
}
