/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:09:28 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/02 22:26:03 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void					init_completion_bin(t_read **read_std)
{
	if (!((*read_std)->tab_ = (t_tab *)ft_memalloc(sizeof(t_tab))))
		return ;
	if ((*read_std)->cmd->prev && !is_token((*read_std)->cmd->prev->c))
		(*read_std)->tab_->from = list_to_str(read_std, (*read_std)->cmd);
	else
		(*read_std)->tab_->from = NULL;
}

void					create_comp_bin(t_read **read_std, char **path)
{
	DIR					*dir;
	struct dirent		*repo;
	int					index;
	int					t;

	t = -1;
	index = 0;
	if (!path)
		return ;
	while (path[++t])
		if ((dir = opendir(path[t])))
		{
			while ((repo = readdir(dir)))
				if ((!(*read_std)->tab_->from && repo->d_name[0] != '.') ||
					(!ft_strncmp((*read_std)->tab_->from, repo->d_name,
								ft_strlen((*read_std)->tab_->from))))
				{
					init_files(&((*read_std)->tab_->file), repo->d_name,
							repo->d_type, index++);
				}
			closedir(dir);
		}
	(*read_std)->tab_->element = index;
	ft_memdel_tab(&path);
}

void					complete_binary(t_read **read_std)
{
	init_completion_bin(read_std);
	create_comp_bin(read_std, ft_split(my_getenv("PATH"), ":"));
	log_trace("%s %d",(*read_std)->tab_->from,(*read_std)->tab_->element);
	if ((*read_std)->tab_->element)
		place_cursor(read_std, 1);
	if (!(init_tab_((*read_std)->tab_, (*read_std)->cur.line)))
	{
		(*read_std)->completion = 0;
		return ;
	}
	print_tab(read_std);
	place_cursor(read_std, 0);
}
