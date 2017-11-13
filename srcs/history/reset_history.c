/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:35:21 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/02 16:35:30 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		reset_history(void)
{
	t_hist	*temp;

	if ((temp = gbl_save_history(NULL, REC_STRUCT)) == NULL)
		return ;
	while (temp->next)
		temp = temp->next;
	gbl_save_history(temp, SAVE_STRUCT);
}
