/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:07:01 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/16 18:54:22 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static const t_error	g_err[] =
{
	(t_error){SYNTAX_ERR, "syntax error near unexpected token `", -1},
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

void			ft_err(char *str, int err)
{
	short		index;

	index = 0;
	while (index < 1)
	{
		if (err == g_err[index].err_type)
		{
			print_error(str, g_err[index].str);
			var_return(1);
		}
		index++;
	}
}
