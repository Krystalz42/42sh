/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   looking_for_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:10:14 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/20 08:07:41 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char		*create_trial_path(char *path, char *binary)
{
	char		*complete_path;

	complete_path = (char *)ft_memalloc(sizeof(char)
	* (ft_strlen(path) + ft_strlen(binary) + 2));
	ft_strcpy(complete_path, path);
	ft_strcpy(complete_path + ft_strlen(complete_path), "/");
	ft_strcpy(complete_path + ft_strlen(complete_path), binary);
	return (complete_path);
}

void		collect_path(char **binary)
{
	char		**path;
	int			index;
	char		*temp;

	if (!ft_strlen(*binary))
		return ;
	if ((path = ft_strsplit(my_getenv("PATH"), ':')) == NULL)
		return ;
	index = 0;
	while (path[index])
	{
		temp = create_trial_path(path[index], *binary);
		if (access(temp, X_OK) == 0)
		{
			add_hash(*binary, temp, 1);
			ft_memdel((void **)binary);
			ft_memdel_tab(&path);
			*binary = temp;
			return ;
		}
		ft_memdel((void **)&temp);
		index++;
	}
	ft_memdel_tab(&path);
}

int			looking_for_path(char **binary)
{
	char		*temp;

	if ((temp = search_path(*binary)))
	{
		free(*binary);
		(*binary) = temp;
		return (1);
	}
	else
		collect_path(binary);
	return (0);
}
