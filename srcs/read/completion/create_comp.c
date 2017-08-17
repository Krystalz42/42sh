/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:48:03 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/17 18:27:50 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		create_comp(t_read **read_std, t_path f)
{
	DIR					*dir;
	struct dirent		*repo = 0;
	int					index;

	index = 0;
	STR_FD("CREATE_COMP", fdb);
	CHAR_FD(10, fdb);
	STR_FD(f.path, fdb);
	CHAR_FD(10, fdb);
	STR_FD(f.to_comp, fdb);
	CHAR_FD(10, fdb);
	if (!f.path)
	{
		if ((dir = opendir(".")))
			while ((repo = readdir(dir)))
				if (repo->d_name[0] != '.')
					init_files(&((*read_std)->comp->tab_->file), repo->d_name, repo->d_type, index++);
		(*read_std)->comp->tab_->element = index;
	}
	else
	{
		if ((dir = opendir(f.path)))
			while ((repo = readdir(dir)))
				if ((!f.to_comp && repo->d_name[0] != '.') || (f.to_comp && !ft_strncmp(repo->d_name, f.to_comp, ft_strlen(f.to_comp) - 1)))
					init_files(&((*read_std)->comp->tab_->file), repo->d_name, repo->d_type, index++);
		(*read_std)->comp->tab_->element = index;
	}
	closedir(dir);
}
