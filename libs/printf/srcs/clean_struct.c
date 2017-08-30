/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_printf.h>

void	clean_struct(t_fmtid *id)
{
	if (id->flag != NULL)
		ft_memdel((void **)&(id->flag));
	if (id->full_arg != NULL)
		ft_memdel((void **)&(id->full_arg));
	if (id->dif != NULL)
		ft_memdel((void **)&(id->dif));
}
