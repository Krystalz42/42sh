/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:07:01 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 14:58:40 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static const t_error	g_err[] =
{
	(t_error){SYNTAX_ERR, "syntax error near unexpected token `", 258},
	(t_error){ENV_ERR, "Environment variable is not defined `", 1},
	(t_error){FILE_404, "No such file or directory `", 1},
	(t_error){EXE_403, "Permission denied `", 1},
	(t_error){NOT_DIR, "Is not a directory `", 1}
};

/*
*************** PUBLIC *********************************************************
*/

void			print_error(char *str, char *err)
{
	ft_putstr("42sh: ");
	ft_putstr(err);
	ft_putstr(str);
	ft_putendl("\'");
}

uint8_t			ft_err(char *str, int err)
{
	short		index;

	index = 0;
	while (index < 5)
	{
		if (err == g_err[index].err_type)
		{
			print_error(str, g_err[index].str);
			var_return(g_err[index].err_ret);
			break ;
		}
		index++;
	}
	return (g_err[index].err_ret);
}
