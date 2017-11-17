/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/17 14:55:47 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
*************** TOOLS **********************************************************
*/

static char		*ft_threejoin(char *s1, char *separator, char *s2)
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

/*
*************** PRIVATE ********************************************************
*/

static uint8_t	change_direction(char *str)
{
	char		*direction;

	if (!str || !ft_strcmp(str, "--"))
	{
		direction = my_getenv("HOME");
		return (direction ? chdir(direction) : ft_err(NULL, ENV_ERR));
	}
	else if (!ft_strcmp(str, "-"))
	{
		direction = my_getenv("OLDPWD");
		return (direction ? chdir(direction) : ft_err(NULL, ENV_ERR));
	}
	else if ((chdir(str)) == -1)
	{
		if (errno == ENOENT)
			return (ft_err(str, FILE_404));
		else if (errno == EACCES)
			return (ft_err(str, EXE_403));
		else if (errno == ENOTDIR)
			return (ft_err(str, NOT_DIR));
	}
	return (0);
}

static void		modify_variable(char *variable, char **pwd)
{
	char		*str;

	str = ft_threejoin(variable, "=", *pwd);
	special_getenv(str);
	add_environment(str);
	ft_memdel((void **)&str);
	ft_memdel((void **)pwd);
}

/*
*************** PUBLIC *********************************************************
*/

uint8_t			builtin_cd(t_node *node, int info)
{
	char				err;
	char				*oldpwd;
	char				*pwd;

	(void)info;
	oldpwd = getcwd(NULL, 4096);
	err = change_direction(node->content->command[1]);
	if (err)
	{
		pwd = getcwd(NULL, 4096);
		modify_variable("OLDPWD", &oldpwd);
		modify_variable("PWD", &pwd);
	}
	ft_memdel((void **)&oldpwd);
	return (var_return(err));
}
