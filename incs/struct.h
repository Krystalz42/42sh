/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:43:12 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/11 06:41:27 by aroulin          ###   ########.fr       */
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

typedef struct		s_cmd
{
	char			c;
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

typedef struct		s_read
{
	t_cmd			*cmd;	
}					t_read;

typedef struct		s_cmp
{
	char			key;
	int				(*function)(t_read **read_std);
}					t_cmp;

typedef struct		s_cmp2
{
	char			*key;
	int				(*function)(t_read **read_std);
}					t_cmp2;

#endif
