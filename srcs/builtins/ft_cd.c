/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/10/24 15:42:03 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char				*ft_path(char *var, unsigned int begin)
{
	char			*path;
	unsigned int	i;
	unsigned int	size;

	i = 0;
	if ((size = (ft_strlen(var) - begin) + 1) == 1 ||
		!(path = malloc(sizeof(char) * (ft_strlen(var) - begin) + 1)))
		return (NULL);
	while (var[begin])
	{
		path[i] = var[begin];
		i++;
		begin++;
	}
	path[i] = 0;
	return (path);
}

static int			cd_home(char **env)
{
	char			*path;
	signed int		i;

	if ((i = search_in_tab(env, "HOME=")) == -1 ||
		(path = ft_path(env[i], 5)) == NULL)
		return (ft_error("HOME", " is not set.", -1));
	if (chdir(path) == -1)
		return (ft_error(path, ": No such file or directory.", -1));
	// Need to accurate the error (Permission denied, Not a directory)
	ft_putendl(path);
	free(path);
	return (0);
}


static int			cd_path(char *path)
{
	if (chdir(path) == -1)
		return (ft_error(path, ": No such file or directory.", -1));
	// Need to accurate the error (Permission denied )
	return (0);
}

static int			cd_oldpwd(char **env)
{
	char			*path;
	signed int		i;

	i = -1;
	if ((i = search_in_tab(env, "OLDPWD=")) == -1 ||
		(path = ft_path(env[i], 7)) == NULL)
		return (ft_error("OLDPWD", " is not set.", -1));
	if (chdir(path) == -1)
		return (ft_error(path, ": No such file or directory.", -1));
	// Need to accurate the error (Permission denied, Not a directory)
	free(path);
	return (0);
}

//Pointer of env and call refresh_varenv at end of function (?)
uint8_t				ft_cd(char **command, char **env)
{
	int				ret;

	if (!command[1] || !ft_strcmp(command[1], "~"))
		ret = cd_home(env);
	else if (!ft_strcmp(command[1], "-"))
		ret = cd_oldpwd(env);
	else
		ret = cd_path(command[1]);
	//if (ret == 0)
	//	refresh_varenv(env);
	return (var_return(ret));
}
