/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/02 18:07:21 by aroulin          ###   ########.fr       */
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
	size_t				flag;
	struct s_list		*next;
	struct s_list		*before;
}						t_list;

typedef struct			s_tree
{
	char				*content;
	struct s_tree		*left;
	struct s_tree		*right;
}						t_tree;

int						get_next_line(int fd, char **line);
int						my_gnl(int fd, char **line);

#endif
