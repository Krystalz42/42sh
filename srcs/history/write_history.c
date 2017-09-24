/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:45:32 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 20:02:06 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_hist			*set_history_to_last(void)
{
	t_hist *hist;

	hist = gbl_save_history(NULL, 1);
	while (hist && hist->prev)
		hist = hist->prev;
	return (hist);
}

int				b_write_history_in_file(char *path)
{
	t_hist	*hist;
	int		fd;
	int		i;

	fd = open(path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	hist = set_history_to_last();
	i = -1;
	while (hist)
	{
		hist->hist->cmd = first_cmd(hist->hist->cmd, 1);
		while (hist->hist->cmd->c)
		{
			CHAR_FD(hist->hist->cmd->c, fd);
			hist->hist->cmd = hist->hist->cmd->next;
		}
		CHAR_FD(10, fd);
		hist = hist->next;
	}
	free(path);
	close(fd);
	return (1);
}
