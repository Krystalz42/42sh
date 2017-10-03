/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:05:05 by jle-quel          #+#    #+#             */
/*   Updated: 2017/09/05 18:09:47 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static t_struct	*ft_newnode(void)
{
	t_struct	*node;

	if (!(node = (t_struct*)malloc(sizeof(t_struct))))
		return (NULL);
	if (!(node->content = ft_memalloc(1)))
		return (NULL);
	node->next = NULL;
	return (node);
}

static char		*ft_populateline(t_struct *node, char **line)
{
	size_t		index;
	char		*memory;

	index = 0;
	while (node->content[index])
	{
		if (node->content[index] == '\n')
		{
			*line = ft_strsub(node->content, 0, index);
			memory = node->content;
			node->content = ft_strdup(node->content + (index + 1));
			free(memory);
			return (node->content);
		}
		index++;
	}
	*line = ft_strdup(node->content);
	ft_strclr(node->content);
	return (node->content);
}

static int		ft_read(const int fd, t_struct *node)
{
	int			ret;
	char		*buf;
	char		*memory;

	if (!(buf = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	while (ft_strchr(node->content, '\n') == 0)
	{
		if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[ret] = '\0';
		memory = node->content;
		if (!(node->content = ft_strjoin(node->content, buf)))
			return (-1);
		free(memory);
		if (ret < BUFF_SIZE)
			break ;
	}
	ft_strdel(&buf);
	return (ret);
}

int				get_next_line(const int fd, char **line)
{
	int					ret;
	static t_struct		*node;

	if (!node)
		node = ft_newnode();
	if (fd == -1 || !line)
		return (-1);
	if ((ret = ft_read(fd, node)) == -1)
		return (-1);
	node->content = ft_populateline(node, line);
	if (!ft_strlen(node->content) && !ft_strlen(*line) && !ret)
		return (0);
	return (1);
}
