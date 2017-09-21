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

	*max_len += 100;
	tmp = (char *)ft_memalloc(sizeof(char) * ((*max_len) + 1));
	ft_bzero(tmp, (*max_len) + 1);
	ft_strcpy(tmp, *buff);
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
	ft_bzero((*line), max_len + 1);
	while ((ret = read(fd, &((*line)[++i]), sizeof(char))) > 0)
	{
		if ((*line)[i] == 10)
		{
			(*line)[i] = '\0';
			return (1);
		}
		if (i == max_len)
			add_size(line, &max_len);
	}
	if (!ret && !i)
		ft_memdel((void **)line);
	return (ret);
}


