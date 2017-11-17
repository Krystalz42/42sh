/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct_for_read.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 14:32:43 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 16:41:20 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
#include "../../../libs/libft/incs/libft.h"

t_read	*init_struct_for_read(void)
{
	t_read	*read_std;

	if (!(read_std = (t_read *)ft_memalloc(sizeof(t_read))))
		return (NULL);
	if (!(read_std->cmd = create_element('\0')))
		return (NULL);
	read_std->hist_search = NULL;
	gbl_save_read(read_std->cmd);
	read_std->history_search = 0;
	return (read_std);
}
