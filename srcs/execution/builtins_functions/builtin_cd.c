/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/17 01:57:46 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

// static unsigned char	change_direction(char *argv, char **env)
// {
// 	char				err;
// 	char				*direction;
//
// 	if (!argv || !ft_strcmp(argv, "--"))
// 	{
// 		direction = ft_getenv(env, "HOME");
// 		return (direction ? chdir(direction) : p_error(NULL, " HOME not set"));
// 	}
// 	if (!ft_strcmp(argv, "-"))
// 	{
// 		direction = ft_getenv(env, "OLDPWD");
// 		return (direction ? chdir(direction) : p_error(NULL, "OLDPWD not set"));
// 	}
// 	else
// 	{
// 		if (access(argv, F_OK) == -1)
// 			err = p_error(argv, "no such file or directory: ");
// 		else
// 		{
// 			err = chdir(argv);
// 			err == -1 ? p_error(argv, "permission denied: ") : 0;
// 		}
// 	}
// 	return (err);
// }


/*
*************** PRIVATE ********************************************************
*/

static unsigned char	change_direction(char *str)
{
	// char				err;
	char				*direction;

	if (!str || !ft_strcmp(str, "--"))
	{
		direction = my_getenv("HOME");
		if (direction)
			chdir(direction);
		else
		{
			ft_err(NULL, ENV_ERR);
			return (-1);
		}
	}
	else if (!ft_strcmp(str, "-"))
	{
		direction = my_getenv("OLDPWD");
		if (direction)
			chdir(direction);
		else
		{
			ft_err(NULL, ENV_ERR);
			return (-1);
		}
	}
	else
	{
		if ((chdir(str)) == -1)
		{
			if (errno == ENOENT)
				ft_putstr("YA PAS BOLOSS");
			if (errno == EACCES)
				ft_putstr("PAS LE DROIT");

			if (errno == ENOTDIR)
				ft_putstr("PAS UN DIR");
				return (-1);
		}
	}
	return (0);
}

char			*ft_threejoin(char *s1, char *separator, char *s2)
{
	char		*str;

	str = NULL;
	if (s1 && separator && s2)
	{
		str = (char*)ft_memalloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(separator) + ft_strlen(s2) + 1));
		ft_strcpy(str, s1);
		ft_strcat(str, separator);
		ft_strcat(str, s2);
	}
	return (str);
}


static void				modify_variable(char *variable, char **pwd)
{
	char				*str;

	str = ft_threejoin(variable, "=", *pwd);
	special_getenv(str);
	add_environment(str);
	ft_memdel((void **)&str);
	ft_memdel((void **)pwd);
}


/*
*************** PUBLIC *********************************************************
*/

uint8_t			builtin_cd(t_node *node, int info __attribute__((unused)))
{
	char				err;
	char				*oldpwd;
	char				*pwd;

	oldpwd = getcwd(NULL, 4096);
	err = change_direction(node->content->command[1]);
	if (!err)
	{
		pwd = getcwd(NULL, 4096);
		modify_variable("OLDPWD", &oldpwd);
		modify_variable("PWD", &pwd);
	}
	ft_memdel((void **)&oldpwd);
	return (var_return(err));
}
