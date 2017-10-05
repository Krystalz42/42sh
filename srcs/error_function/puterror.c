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


void			puterror(char *err)
{
	STR_FD("42sh: ", STDERR_FILENO);
	STR_FD(err, STDERR_FILENO);
	CHAR_FD(10, STDERR_FILENO);
	exit(EXIT_FAILURE);
}
