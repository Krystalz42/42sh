/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 16:45:32 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/19 16:45:33 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static t_hist     *set_history_to_last(void)
{
    t_hist *hist;

    hist = gbl_save_history(NULL);
    while (hist && hist->prev)
        hist = hist->prev;
    return (hist);
}

void            write_history(void)
{
    int     fd;
    t_hist  *hist;
    char    buff[500 * MAX_COMMAND];
    int     i;
    char    *path_history;

    i = -1;
    if (!(path_history = get_str_from_history()))
        return ;
    remove(path_history);
    fd = open(path_history, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    hist = set_history_to_last();
    ft_bzero(buff, 500 * MAX_COMMAND);
    while (hist)
    {
        hist->hist->cmd = first_cmd(hist->hist->cmd, 1);
        while (hist->hist->cmd->c)
        {
            buff[++i] = hist->hist->cmd->c;
            hist->hist->cmd = hist->hist->cmd->next;
        }
        buff[++i] = 10;
        hist = hist->next;
    }
    STR_FD(buff, fd);
    free(path_history);
    close(fd);
}