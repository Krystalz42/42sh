/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 13:26:50 by aroulin           #+#    #+#             */
/*   Updated: 2017/04/02 19:16:18 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 3

typedef struct	s_file
{
	int					fd[50];
	char				*d[50];
	int					bol[50];
	int					count[50];
	int					first;
	int					i;
}				t_file;

int				get_next_line(int fd, char **line);

#endif
