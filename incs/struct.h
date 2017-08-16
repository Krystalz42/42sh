/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:43:12 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/13 08:05:31 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_mouse
{
	int						x;
	int						x2;
	int						y;
}					t_mouse;

typedef struct		s_cmd
{
	char			c;
	int				s;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct		s_file
{
	char			*name;
	unsigned char	type;
	int				select;
	int				index;
	struct s_file	*next;
	t_mouse			ms;
}					t_file;

typedef struct		s_tab
{
	t_file			*file;
	int				element;
	int				len;
	int				co;
	int				li;
	int				index;
	int				nbr;
}					t_tab;

typedef struct		s_completion
{
	int				fd;
	t_tab			*tab_;
	int				element;
}					t_completion;

typedef struct		s_cursor
{
	int				line;
	int				co;
}					t_cursor;

typedef struct		s_read
{
	t_cmd			*cmd;	
	t_completion	*comp;
	int				completion;
	t_cursor		cur;
	int				history;
}					t_read;

typedef struct		s_cmp
{
	char			*key;
	int				(*function)(t_read **read_std);
	size_t			len;
}					t_cmp;


#endif
