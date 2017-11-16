//
// Created by Alexandre ROULIN on 11/16/17.
//

#include <sh.h>

static int			check_this_one(char *part, char *path, char *from)
{
	if (access(part, F_OK) == -1)
		return (error_msg(from, NO_DIRECTORY, path));
	if (access(part, X_OK) == -1)
		return (error_msg(from, NO_RIGHT, path));
	return (0);
}

int					check_path(char *path, char *from)
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
			part = ft_strjoin(part, pieces[i]);
		if (check_this_one(part, path, from) == 1)
			break ;
		i++;
	}
	free(part);
	ft_memdel_tab(&pieces);
	return (1);
}
