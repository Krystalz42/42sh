/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_research.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 17:10:23 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/04 17:24:56 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int				init_research(t_read **read_std)
{
	if (!((*read_std)->hist_search = (t_lfh *)ft_memalloc(sizeof(t_lfh))))
		return (--(*read_std)->history_search);
	(*read_std)->hist_search->cmd = create_element('\0');
	print_struct_history(read_std);
	return (0);
}
