/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 21:07:41 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/12 21:54:40 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

#include <libft.h>
#include <unistd.h>
#include <struct.h>
#include <stdio.h>
#include <stdlib.h>
#include <define.h>
#include <termios.h>
#include <fcntl.h>
#include <curses.h>
#include <term.h>

int					shell(void);

/*
**				FUNCTION READ AND RETURN A STRUCT
*/

t_read				*read_stdin(void);

int					key_tab(t_read **read_std);
int					key_print_(t_read **read_std, char c);
int					key_enter_(t_read **read_std);
int					key_interrupt(t_read **read_std);
int					key_clear_(t_read **read_std);
int					del_key(t_read **read_std);
int					key_eof(t_read **read_std);
int					arrow_left(t_read **read_std);
int					arrow_right(t_read **read_std);
int					arrow_up(t_read **read_std);
int					arrow_down(t_read **read_std);
int					home_key(t_read **read_std);
int					del_key(t_read **read_std);
int					shift_up_key(t_read **read);
int					shift_down_key(t_read **read);
int					shift_left_key(t_read **read);
int					shift_right_key(t_read **read);
int					end_key(t_read **read_std);

/*
**				ENVIRONEMENT FUNCTION
*/

t_env				*gbl_save_env(unsigned short flags, t_env *env);
void				init_env(void);
void				split_env(char *env);
void				add_list_env(char *name, char *value);
char				*my_getenv(char *str);

/*
**				TERMIOS FUNCTION
*/

struct termios		keep_term_struct(unsigned short flags, struct termios *term);
void				set_termios(unsigned short flags);
int					init_fd(void);
int					init_term(void);

#endif
