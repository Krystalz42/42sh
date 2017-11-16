//
// Created by Alexandre ROULIN on 11/16/17.
//

#include <sh.h>
#include <sys/stat.h>

static int			check_this_one(char *part, char *path)
{
	struct stat		sts;

	lstat(part, &sts);
	if (access(part, F_OK) == -1)
		return (error_msg(S42H, NO_DIRECTORY, path));
	if (S_ISDIR(sts.st_mode) || S_ISLNK(sts.st_mode))
		return (error_msg(S42H, IS_DIR, path));
	if (access(part, X_OK) == -1)
		return (error_msg(S42H, NO_RIGHT, path));
	return (0);
}

int					check_path(char *path)
{
	char			**table;
	int				index;
	char			*temp;

	if ((table = ft_strsplit(path, '/')))
			return (check_this_one(path, path) ? -1 : 1);
	index = 0;
	temp = NULL;
	while (table[index])
	{
		ft_strdel(&temp);
		if (index == 0)
			temp = create_trial_path(table[index], table[index + 1]);
		else
			temp = create_trial_path(temp, table[index]);
		if (check_this_one(temp, path) == 1)
		{
			ft_strdel(&temp);
			ft_memdel_tab(&table);
			return (-1);
		}
		index++;
	}
	ft_memdel_tab(&table);
	return (1);
}
