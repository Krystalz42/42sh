/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_os_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 19:56:04 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/24 19:56:05 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_outstanding			*get_os_pointer(t_outstanding *get, int flags)
{
	static t_outstanding			*save;

	if (flags)
		save = NULL;
	else if (get)
		save = get;
	return (save);
}