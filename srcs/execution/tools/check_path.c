/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:16:01 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/15 21:48:55 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int			check_this_one(char *part, char *path)
{
	(void)part; (void)path;
	if (errno == ENOENT)
		return (error_msg(S42H, "No such file or directory", NULL));
	else if (errno == EACCES)
		return (error_msg(S42H, "permission denied", NULL));
	else if (errno == ENOTDIR)
		return (error_msg(S42H, "is a directory", NULL));
	return (0);
}

void				check_path(char *path)
{
	char			**table;
	int				index;
	char			*temp;

	if ((table = ft_strsplit(path, '/')) == NULL)
		exit(check_this_one(path, path) ? 0 : 1);
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
			exit(var_return(1));
		}
		index++;
	}
	ft_memdel_tab(&table);
	exit(var_return(1));
}
