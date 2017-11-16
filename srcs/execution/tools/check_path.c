//
// Created by Alexandre ROULIN on 11/16/17.
//

#include <sh.h>
#include <sys/stat.h>

static int			check_this_one(char *part, char *path)
{
	struct stat		sts;

	if (access(part, F_OK) == -1)
		return (error_msg(S42H, NO_DIRECTORY, path));
	lstat(part, &sts);
	if (S_ISDIR(sts.st_mode) || S_ISLNK(sts.st_mode))
		return (error_msg(S42H, IS_DIR, path));
	if (access(part, X_OK) == -1)
		return (error_msg(S42H, NO_RIGHT, path));
	return (0);
}

int					check_path(char *path)
{
	char			**pieces;
	char			*part;
	unsigned int	i;

	i = 0;
	if (access(path, F_OK) == -1)
		return (0);
	if ((pieces = ft_split(path, "/")) == NULL)
	{
		error_msg(UCD, NO_ARG, NULL);
		return (-1);
	}
	while (pieces[i])
	{
		if (i == 0)
			part = ft_strdup(pieces[i]);
		else
			part = ft_strjoin(part, pieces[i]);
		if (check_this_one(part, path) == 1)
		{
			free(part);
			ft_memdel_tab(&pieces);
			return (-1);
		}
		i++;
	}
	free(part);
	ft_memdel_tab(&pieces);
	return (1);
}
