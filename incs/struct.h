/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:43:12 by aroulin           #+#    #+#             */
/*   Updated: 2017/12/20 15:01:50 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "struct2.h"

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
**			ALIAS HISTORY
*/

typedef struct				s_alias
{
	char					*variable;
	char					*value;
	size_t					times;
	struct s_alias			*next;
}							t_alias;

/*
**			STRUCT FOR HASH
*/

typedef struct				s_hash
{
	char					*binary;
	char					*path;
	char					*alias;
	size_t					times;
	struct s_hash			*next;
}							t_hash;

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
	t_cmd					*history_compare;
	t_cursor				cur;
	int						completion;
	int						history_search;
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
	struct s_parsing		*right;
	struct s_parsing		*left;
}							t_parsing;

/*
**			STRUCT FOR BUILTINS
*/

typedef struct				s_builtin
{
	const char				*str;
	uint8_t					(*function)(t_parsing *node, int info);
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
	struct s_jobs			*next_use;
	struct s_jobs			*prev_use;
}							t_jobs;

/*
**			STRUCT FOR STATUS SIGNAL
*/

typedef struct				s_signal
{
	int						signal;
	char					*status;
}							t_signal;

#endif
