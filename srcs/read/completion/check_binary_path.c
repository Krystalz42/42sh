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
    static const char		token[] = "|;&";
    int				i;

    i = -1;
    while (++i < 3)
        if (token[i] == c)
            return (1);
    return (0);
}

int			check_word(t_cmd *cmd)
{
    if (cmd->c == '.' || cmd->c == '/')
        return (0);
    while (cmd->prev)
    {
        if (cmd->prev->c == 32)
        {
            while (cmd->prev)
            {
                if (is_token(cmd->prev->c))
                    return (1);
                else if (ft_isalnum(cmd->prev->c))
                    return (0);
                cmd = cmd->prev;
            }
        }
        else
        {
            while (cmd->prev && cmd->prev->c != 32)
                cmd = cmd->prev;
            return (check_word(cmd));
        }
    }
    return (1);
}
