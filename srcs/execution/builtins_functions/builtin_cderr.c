/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cderr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:24:32 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/17 01:50:59 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char		*create_path(char *s1, char *s2)
{
	ft_strcpy(s1 + ft_strlen(s1), s2);
	ft_strcpy(s1 + ft_strlen(s1), "/");
	return (s1);
}

char		*check_this_one(char *path)
{
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) == 0)
			return ("C PAS UN REPO\n");
		else
			return ("TU PEU PAS ENTER BATAR KI LA DI JEFF\n");
	}
	else
	{
		if (errno == ENOTDIR)
			return ("NOT DIRECTORY\n");
		if (errno == ENOENT)
			return ("ENOENT\n");
	}
	return (NULL);
}

char					*check_directory(char **path, char *temp)
{
	char			*error;

	if (*path)
	{
		if ((error = check_this_one(create_path(temp, *path))))
			return (error);
		else
			return (check_directory(path + 1, create_path(temp, *path)));
	}
	return (NULL);
}
