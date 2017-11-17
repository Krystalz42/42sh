/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 17:22:31 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 25600

typedef struct			s_fd
{
	int					fd;
	char				*keep;
}						t_fd;

typedef struct			s_struct
{
	char				*content;
	struct s_struct		*next;
}						t_struct;

typedef struct			s_list
{
	char				*content;
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;

int						get_next_line(int fd, char **line);
int						my_gnl(int fd, char **line);

#endif
