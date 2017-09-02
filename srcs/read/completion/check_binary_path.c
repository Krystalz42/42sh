/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_binary_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 16:21:04 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/02 16:21:07 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			is_token(char c)
{
    const char		*token;
    int				i;

    token = "|;&";
    i = 0;
    while (++i < 3)
        if (token[i] == c)
            return (1);
    return (0);
}

int			check_word(t_cmd *cmd)
{
    while (cmd->prev)
    {
        if (is_token(cmd->prev->c) || !cmd->prev)
            return (1);
        if (cmd->prev->c != 32 && cmd->prev->c != 9)
            return (0);
        cmd = cmd->prev;
    }
    return (0);
}
