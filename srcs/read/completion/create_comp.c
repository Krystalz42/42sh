/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:48:03 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/17 02:07:19 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		create_comp(t_read **read_std, char *str)
{
	DIR					*dir;
	struct dirent		*repo = 0;
	int					index;

	index = 0;
	if (!str)
	{
		if ((dir = opendir(".")))
			while ((repo = readdir(dir)))
				if (repo->d_name[0] != '.')
					init_files(&((*read_std)->comp->tab_->file), repo->d_name, repo->d_type, index++);
		(*read_std)->comp->tab_->element = index;
	}
	else
	{
		if ((dir = opendir(str)))
			while ((repo = readdir(dir)))
				if (repo->d_name[0] != '.')
					init_files(&((*read_std)->comp->tab_->file), repo->d_name, repo->d_type, index++);
		(*read_std)->comp->tab_->element = index;
	}
	closedir(dir);
}
