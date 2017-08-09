/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 13:03:45 by aroulin           #+#    #+#             */
/*   Updated: 2017/04/18 17:21:21 by aroulin          ###   ########.fr       */
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
