/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/05 18:09:58 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 3


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

typedef	enum			e_bool
{
	true = 1,
	false = -1
}						t_bool;

int				get_next_line(int fd, char **line);

#endif
