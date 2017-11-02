//
// Created by Alexandre ROULIN on 11/2/17.
//

#include <sh.h>

static char 			*create_trial_path(char *path, char *binary)
{
	char		*complete_path;

	complete_path = (char *)ft_memalloc(sizeof(char)
										* (ft_strlen(path) + ft_strlen(binary) + 2));
	ft_strcpy(complete_path, path);
	ft_strcpy(complete_path + ft_strlen(complete_path), "/");
	ft_strcpy(complete_path + ft_strlen(complete_path), binary);
	return (complete_path);
}

static void				collect_path(char **binary)
{
	char			**path;
	int				index;
	char			*temp;

	if ((path = ft_strsplit(my_getenv("PATH="), ':')) == NULL)
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

static int				looking_for_path(char **binary)
{
	char			*temp;

	if ((temp = search_path(*binary)))
	{
		free(*binary);
		(*binary) = temp;
		return (1);
	}
	return (0);
}

void					check_tree_path(t_node *node)
{
	if (node)
	{
		if (node->content->value == VALUE_COMMAND)
			if (check_if_builtin(node, DONT_EXECUTE) == -1)
				if ((looking_for_path(&node->content->command[0])) == 0)
					collect_path(&node->content->command[0]);
		check_tree_path(node->left);
		check_tree_path(node->right);
	}
}

