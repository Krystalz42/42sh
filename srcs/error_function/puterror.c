/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puterror.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 14:06:54 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/02 14:06:58 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static const t_error g_err[] = {
		(t_error){EAGAIN, "Resource temporarily unavailable"},
		(t_error){ENOMEM, "Cannot allocate memory"},
		(t_error){0, NULL}
};


void puterror(char *err) {
	int		i;

	STR_FD("42sh:", STDERR_FILENO);
	STR_FD(err, STDERR_FILENO);
	i = -1;
	while (g_err[++i].err)
		if (g_err[i].err == errno)
			STR_FD(g_err[i].msg, STDERR_FILENO);
	CHAR_FD(10, STDERR_FILENO);
}
