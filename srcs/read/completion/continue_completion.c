/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   continue_completion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 22:29:39 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/02 22:29:43 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			back_completion(t_read **read_std)
{
	t_file	*tmp;

	tmp = (*read_std)->tab_->file;
	tputs(tgetstr(SAVE, 0), STDIN_FILENO, &my_put);
	tputs(tgetstr(MV_BOT, 0), STDIN_FILENO, &my_put);
	while (tmp)
	{
		if (tmp->index == (*read_std)->tab_->index)
		{
			print_element(tmp, 0);
			tmp = tmp->next;
			print_element(tmp, 1);
			break ;
		}
		else if (!(*read_std)->tab_->index && !tmp->next)
		{
			break ;
		}
		tmp = tmp->next;
	}
	tputs(tgetstr(RESTORE, 0), STDIN_FILENO, &my_put);
}

void			continue_completion(t_read **read_std)
{
	t_file	*tmp;

	tmp = (*read_std)->tab_->file;
	tputs(tgetstr("sc", 0), STDIN_FILENO, &my_put);
	tputs(tgetstr(MV_BOT, 0), STDIN_FILENO, &my_put);
	while (tmp)
	{
		if (tmp->index == (*read_std)->tab_->index)
		{
			print_element(tmp, 0);
			tmp = tmp->prev;
			print_element(tmp, 1);
			break ;
		}
		tmp = tmp->next;
	}
	tputs(tgetstr(RESTORE, 0), STDIN_FILENO, &my_put);
}
