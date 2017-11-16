/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cderr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:24:32 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/16 21:33:14 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <sys/stat.h>

static int			check_this_one(char *part, char *path)
{
	struct stat		sts;

	if (access(part, F_OK) == -1)
		return (error_msg(UCD, NO_DIRECTORY, path));
	lstat(part, &sts);
	if (!S_ISDIR(sts.st_mode) && !S_ISLNK(sts.st_mode))
		return (error_msg(UCD, IS_NOTDIR, path));
	if (access(part, X_OK) == -1)
		return (error_msg(UCD, NO_RIGHT, path));
	return (0);
}

static char			*create_path(char *path, char *binary)
{
	char			*complete_path;

	complete_path = (char *)ft_memalloc(sizeof(char) * (ft_strlen(path) + ft_strlen(binary) + 2));
	ft_strcpy(complete_path, path);
	ft_strcpy(complete_path + ft_strlen(complete_path), "/");
	ft_strcpy(complete_path + ft_strlen(complete_path), binary);
	free(path);
	return (complete_path);
}

int					check_directory(char *path)
{
	char			**pieces;
	char			*part;
	unsigned int	i;

	i = 0;
	if ((pieces = ft_split(path, "/")) == NULL)
	{
		error_msg(UCD, NO_ARG, NULL);
		return (0);
	}
	while (pieces[i])
	{
		if (i == 0)
			part = ft_strdup(pieces[i]);
		else
			part = create_path(part, pieces[i]);
		if (check_this_one(part, path) == 1)
			break ;
		i++;
	}
	free(part);
	ft_memdel_tab(&pieces);
	return (1);
}
