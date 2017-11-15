/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cderr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:24:32 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/15 20:32:19 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				cd_check_error(char *path)
{
	if (access(path, F_OK) == ENOENT)
		ft_putstr("not found");
	else
	{
		if (access(path, F_OK) == ENOTDIR)
			ft_putstr("not dir");
		else
		{
			if (access(path, F_OK) == EACCESS)
				ft_putstr("not access");
		}
	}
	return (1);
}
