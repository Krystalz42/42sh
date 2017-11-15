/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cderr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:24:32 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/15 21:12:23 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include <sys/stat.h>

static int		call_error(char *err, char *path)
{
	ft_putstr(UCD);
	ft_putstr(err);
	ft_putendl(path);
	return (1);
}
static int		check_this_one(char *part, char *path)
{
	struct stat	sts;

	if (access(part, F_OK) == -1)
		return (call_error(NO_DIRECTORY, path));
	lstat(part, &sts);
	if (!S_ISDIR(sts.st_mode) && !S_ISLNK(sts.st_mode))
		return (call_error(IS_NOTDIR, path));
	if (access(part, X_OK) == -1)
		return (call_error(NO_RIGHT, path));
	return (0);
}

// Need to cut path in part
int			cd_check_error(char *path)
{
	check_this_one(path, path);
	return (1);
}
