/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cderr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:24:32 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/16 19:02:58 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <sys/stat.h>

static int			call_error(char *err, char *path)
{
	ft_putstr(UCD);
	ft_putstr(err);
	ft_putendl(path);
	return (1);
}
static int			check_this_one(char *part, char *path)
{
	struct stat		sts;

	if (access(part, F_OK) == -1)
		return (call_error(NO_DIRECTORY, path));
	lstat(part, &sts);
	if (!S_ISDIR(sts.st_mode) && !S_ISLNK(sts.st_mode))
		return (call_error(IS_NOTDIR, path));
	if (access(part, X_OK) == -1)
		return (call_error(NO_RIGHT, path));
	return (0);
}

int					cd_check_error(char *path)
{
	char			**pieces;
	char			*part;
	unsigned int	i;

	i = 0;
	pieces = ft_split(path, "/");
	while (pieces[i])
	{
		if (i == 0)
			part = ft_strdup(pieces[i]);
		else
			part = ft_strjoin(part, pieces[i]);
		if (check_this_one(part, path) == 1)
			break ;
		i++;
	}
	free(part);
	i = 0;
	while (pieces[i])
		free(pieces[i++]);
	free(pieces);
	return (1);
}
