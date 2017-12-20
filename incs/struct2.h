/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:59:01 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/20 14:59:36 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT2_H
# define STRUCT2_H

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

#endif
