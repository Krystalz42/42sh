/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:48:03 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/13 05:31:34 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		init_path(t_cmd *tmp, int len)
{
	char		*str;


	if (!(str = ft_strnew(len)))
		return ;
	while (tmp)
	{

	}
}

void		create_comp(t_read **read_std, t_cmd *tmp, int i)
{
	DIR					*dir;
	struct dirent		*repo;
//	char				*str;

	(void)read_std;
	(void)tmp;
	if (!i)
		if ((dir = opendir(".")))
			while ((repo = readdir(dir)))
				if (repo->d_name[0] != '.')
					init_files(&((*read_std)->comp->file), repo->d_name, repo->d_type);

}
