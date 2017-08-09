/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   42sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 21:07:41 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/09 23:59:50 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

#include <libft.h>
#include <unistd.h>
#include <struct.h>
#include <stdio.h>
#include <define.h>

/*
 **				FUNCTION READ AND RETURN A STRUCT
 */

t_read			*read_stdin(void);
int				shell(void);
t_env			*gbl_save_env(unsigned short flags, t_env *env);
void			init_env(void);
void			split_env(char *env);
void			add_list_env(char *name, char *value);

#endif
