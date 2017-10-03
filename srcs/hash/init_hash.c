/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:14:09 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/02 22:18:49 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static size_t		move_index(char *str, size_t index, int (*f)(int))
{
	while (f(str[index]))
		index++;
	return (index);
}

static size_t		add_info(char *str, char **info)
{
	size_t		len;

	len = 0;
	while (str[len] && str[len] != '=')
		len++;
	(*info) = ft_strsub(str, 0, len);
	return (len);
}

static void			init_in_shell(int fd)
{
	char			*line;
	unsigned int	times;
	size_t			index;
	char			*bin;
	char			*path;

	while (my_gnl(fd, &line))
	{
		index = 0;
		times = ft_atoui(line);
		index = move_index(line, index, ft_isdigit);
		index++;
		index += add_info(line + index, &bin);
		index++;
		add_info(line + index, &path);
		add_hash(bin, path, times);
		ft_memdel((void **)&path);
		ft_memdel((void **)&bin);
		ft_memdel((void **)&line);
	}
}

void				init_hash(void)
{
	char	*path_hash;
	int		fd;

	if (!(path_hash = get_str_from_hash()))
		return ;
	if ((fd = open(path_hash, O_RDONLY)) == -1)
	{
		free(path_hash);
		return ;
	}
	init_in_shell(fd);
	free(path_hash);
	close(fd);
}
