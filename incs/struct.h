/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:43:12 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/02 17:33:45 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

#include <stdbool.h>

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
	struct s_file	*prev;
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
	int				elem_page;
	int				page;
	char			*from;
}					t_tab;

/*
**			STRUCT FOR CURSOR
*/

typedef struct		s_cursor
{
	int				line;
	int				co;
	int				save;
}					t_cursor;

/*
**			STRUCT HISTORY
*/

typedef struct		s_hist
{
	struct s_read	*hist;
	struct s_hist	*prev;
	struct s_hist	*next;
}					t_hist;

/*
**			STRUCT FOR HASH
*/

typedef struct		s_hash
{
	char			*binary;
	char			*path;
	size_t			times;
	struct s_hash	*next;
}					t_hash;

/*
**          STRUCT FOR LIST HASH
*/

typedef struct		s_table_hash
{
	t_hash					**hash;
	unsigned int			index;
	struct s_table_hash		*next;
	struct s_table_hash		*prev;
}					t_table_hash;

/*
**			STRUCT FOR SEARCH IN HISTORY
*/

typedef struct		s_lfh
{
	t_cmd			*cmd;
	t_cursor		cur;
}					t_lfh;

/*
**			STRUCT FOR READ_STD
*/

typedef struct		s_read
{
	t_cmd			*cmd;
	t_tab			*tab_;
	t_lfh			*hist_search;
	int				completion;
	int				history_search;
	t_cursor		cur;
	int				history;
	int				finish;
	int				print;
}					t_read;

/*
**			STRUCT FOR COMPARE KEY
*/

typedef struct		s_cmp
{
	unsigned long	key;
	int				(*function)(struct s_read **read_std, unsigned long buff);
}					t_cmp;

/*
**			STRUCT FOR UNDO (OUTSTANDING)
*/

typedef struct		s_outstanding
{
	t_cmd					*cmd;
	unsigned long			movement;
	unsigned long			buff;
	struct s_outstanding	*next;
	struct s_outstanding	*prev;
}					t_outstanding;

/*
**			STRUCT FOR JOB'S CONTROL
*/

typedef struct 		s_process
{
	pid_t 			pid;
	pid_t 			pgid;
	int				status;
	int				foreground;
	int				running;
	char			*command;
}					t_process;

typedef struct 		s_jobs
{
	t_process		father;
	t_process		child[MAX_CHILD];
}					t_jobs;

#endif