/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:43:12 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/18 11:56:51 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>

/*
**			STRUCT FOR ESCAPE
*/

typedef struct				s_esc
{
	char					*esc;
	char					*to_esc;
}							t_esc;

/*
**			STRUCT FOR ERROR
*/

typedef struct				s_error
{
	int						err_type;
	char					*str;
	int						err_ret;
}							t_error;

/*
**			STRUCT FOR TOKEN_RECOGNITION
*/

typedef struct				s_lexing
{
	char					*str;
	int						value;
	int						priority;
}							t_lexing;

/*
**			STRUCT FOR COMPLETION'S PATH
*/

typedef struct				s_path
{
	char					*path;
	char					*to_comp;
}							t_path;

/*
**			STRUCT FOR ENVIRONEMENT
*/

typedef struct				s_env
{
	char					*name;
	char					*value;
	struct s_env			*next;
}							t_env;

/*
**			STRUCT FOR MOUSE
*/

typedef struct				s_mouse
{
	int						x;
	int						y;
}							t_mouse;

/*
**			STRUCT FOR COMMAND
*/

typedef struct				s_cmd
{
	char					c;
	int						value;
	uint8_t					status;
	struct s_cmd			*next;
	struct s_cmd			*prev;
}							t_cmd;

/*
**			STRUCT FOR COMPLETION'S ARGUMENT
*/

typedef struct				s_file
{
	char					*name;
	unsigned char			type;
	int						select;
	int						index;
	struct s_file			*next;
	struct s_file			*prev;
	t_mouse					ms;
}							t_file;

/*
**			STRUCT FOR COMPLETION'S TAB
*/

typedef struct				s_tab
{
	t_file					*file;
	int						element;
	int						len;
	int						co;
	int						li;
	int						index;
	int						nbr;
	int						elem_page;
	int						page;
	char					*from;
}							t_tab;

/*
**			STRUCT FOR CURSOR
*/

typedef struct				s_cursor
{
	int						line;
	int						co;
	int						save;
}							t_cursor;

typedef struct				s_bdata
{
	char					*oldpwd;
	char					*pwd;
}							t_bdata;

/*
**			STRUCT HISTORY
*/

typedef struct				s_hist
{
	struct s_read			*hist;
	struct s_hist			*prev;
	struct s_hist			*next;
}							t_hist;

/*
**			STRUCT FOR HASH
*/

typedef struct				s_hash
{
	char					*binary;
	char					*path;
	size_t					times;
	struct s_hash			*next;
}							t_hash;

/*
**          STRUCT FOR LIST HASH
*/

typedef struct				s_table_hash
{
	t_hash					**hash;
	unsigned int			index;
	struct s_table_hash		*next;
	struct s_table_hash		*prev;
}							t_table_hash;

/*
**			STRUCT FOR SEARCH IN HISTORY
*/

typedef struct				s_lfh
{
	t_cmd					*cmd;
	t_cursor				cur;
}							t_lfh;

/*
**			STRUCT FOR READ_STD
*/

typedef struct				s_read
{
	t_cmd					*cmd;
	t_tab					*tab_;
	t_lfh					*hist_search;
	int						completion;
	int						history_search;
	t_cursor				cur;
	int						history;
	int						finish;
	int						print;
}							t_read;

/*
**			STRUCT FOR COMPARE KEY
*/

typedef struct				s_cmp
{
	unsigned long			key;
	int						(*function)(struct s_read **read_std,
							unsigned long buff);
}							t_cmp;

/*
**			STRUCT FOR PARSING
*/

typedef struct				s_parsing
{
	char					*input;
	char					**command;
	char					*heredoc;
	char					**env;
	int						env_option;
	int						value;
	int						priority;
	struct s_parsing		*prev;
	struct s_parsing		*next;
}							t_parsing;

typedef struct				s_node
{
	t_parsing				*content;
	struct s_node			*right;
	struct s_node			*left;
}							t_node;

/*
**			STRUCT FOR BUILTINS
*/

typedef struct				s_builtin
{
	const char				*str;
	uint8_t					(*function)(t_node *node, int info);
}							t_builtin;

/*
**			STRUCT FOR UNDO (OUTSTANDING)
*/

typedef struct				s_outstanding
{
	t_cmd					*cmd;
	unsigned long			movement;
	unsigned long			buff;
	struct s_outstanding	*next;
	struct s_outstanding	*prev;
}							t_outstanding;

/*
**			STRUCT FOR JOB'S CONTROL
*/

typedef struct				s_process
{
	pid_t					pid;
	pid_t					pgid;
	int						status;
	int						foreground;
	int						running;
	char					*command;
	int						fildes[2];
	int						finished;
	struct s_process		*next;
	struct s_process		*prev;
}							t_process;

typedef struct				s_jobs
{
	int						index;
	t_process				*process;
	struct s_jobs			*next;
	struct s_jobs			*prev;
}							t_jobs;

/*
**			STRUCT FOR STATUS SIGNAL
*/

typedef struct				s_signal
{
	int						signal;
	char					*status;
}							t_signal;

/*
**			ENUM FOR EXECUTING
*/

typedef uint8_t				(t_exec)(t_node *node, t_jobs *jobs, int info);

#endif
