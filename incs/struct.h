/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:43:12 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/19 22:33:06 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
**			STRUCT FOR COMPLETION'S PATH
*/

typedef struct		s_path
{
	char			*path;
	char			*to_comp;
}					t_path;

/*
**			STRUCT FOR ENVIRONEMENT
*/

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

/*
**			STRUCT FOR MOUSE 
*/

typedef struct		s_mouse
{
	int						x;
	int						y;
}					t_mouse;

/*
**			STRUCT FOR COMMAND
*/

typedef struct		s_cmd
{
	char			c;
	int				s;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

/*
**			STRUCT FOR COMPLETION'S ARGUMENT
*/

typedef struct		s_file
{
	char			*name;
	unsigned char	type;
	int				select;
	int				index;
	struct s_file	*next;
	t_mouse			ms;
}					t_file;

/*
**			STRUCT FOR COMPLETION'S TAB
*/

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

/*
**			STRUCT FOR COMPLETION
*/

typedef struct		s_completion
{
	int				fd;
	t_tab			*tab_;
	char			*from;
	int				element;
}					t_completion;

/*
**			STRUCT FOR CURSOR
*/

typedef struct		s_cursor
{
	int				line;
	int				co;
}					t_cursor;

/*
**			STRUCT FOR READ_STD
*/

typedef struct		s_read
{
	t_cmd			*cmd;	
	t_completion	*comp;
	int				completion;
	t_cursor		cur;
	int				history;
	int				finish;
}					t_read;

/*
**			STRUCT FOR COMPARE KEY
*/

typedef struct		s_cmp
{
	char			*key;
	int				(*function)(t_read **read_std);
}					t_cmp;

#endif
