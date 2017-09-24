/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:55:50 by aroulin           #+#    #+#             */
/*   Updated: 2017/04/18 17:17:18 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void        add_size(char **buff, int *max_len)
{
	char *tmp;

	tmp = (char *)ft_memalloc(sizeof(char) * ((*max_len) + 101));
	ft_strncpy(tmp, *buff, *max_len);
	*max_len += 100;
	ft_memdel((void **)buff);
	(*buff) = tmp;
}

int         my_gnl(int fd, char **line)
{
	int     max_len;
	int     i;
	int     ret;

	if (fd == -1 || !line)
		return (0);
	i = -1;
	max_len = 100;
	(*line) = (char *)ft_memalloc(sizeof(char) * (max_len + 1));
	while ((ret = read(fd, &((*line)[++i]), sizeof(char))) > 0)
	{
		if ((*line)[i] == 10)
			break ;
		if (i == max_len)
			add_size(line, &max_len);
	}
	if (i)
	{
		(*line)[i] = '\0';
		return (1);
	}
	else if ((!ret && !i))
		ft_memdel((void **)line);
	return (ret);
}


