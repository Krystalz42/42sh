/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_cursor_prompt.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/04 17:39:18 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/04 17:39:27 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int         new_line_after_bloc(t_read **read_std, int to)
{
    if (to == 2)
    {
        (*read_std)->cur.save = (*read_std)->cur.line;
        reset(read_std, 0);
        insert_one_line();

    }
    else if (to == 1)
    {
        (*read_std)->cur.save = (*read_std)->cur.line;
        reset(read_std, 0);
        MV_BOT;
    }
    else
    {
        MV_TOP;
        reset(read_std, 1);
    }
    return (1);
}

int         prompt_history(int p)
{
    char *prompt;

    prompt = "search in history : ";
    if (p)
        STR_FD("\x1B[31m", init_fd());
    STR_FD(prompt, init_fd());
    P_RST_FD(init_fd());
    return (ft_strlen(prompt) + 3);
}
