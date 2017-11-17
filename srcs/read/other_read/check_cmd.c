/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 21:05:29 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 16:45:19 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static inline int	is_quote(char cmd)
{
	static const char		buff[] = "\'\"";
	int						i;

	i = -1;
	while (++i < 2)
		if (cmd == buff[i])
			return (1);
	return (0);
}

static inline int	launch_rec(char cmd, char c)
{
	if (is_quote(cmd) && !is_quote(c))
		return (1);
	return (0);
}

static inline int	stop_rec(char cmd, char c)
{
	if (is_quote(c) && is_quote(cmd) && cmd == c)
		return (1);
	return (0);
}

static char			rec_brackets(t_cmd *cmd, char c)
{
	if (cmd == NULL)
		return (!c ? (char)'\\' : c);
	if (cmd->c == '\\' && c != '\'')
		return (rec_brackets(cmd->next->next, c));
	if (launch_rec(cmd->c, c))
		return (rec_brackets(cmd->next, cmd->c));
	if (stop_rec(cmd->c, c))
		return (rec_brackets(cmd->next, '\0'));
	if (cmd->c)
		return (rec_brackets(cmd->next, c));
	return (c);
}

int					check_cmd(t_read **read_std)
{
	char		c;

	c = rec_brackets(first_cmd((*read_std)->cmd, 1), '\0');
	if (c == '\'')
		prompt(QUOTE);
	else if (c == '\"')
		prompt(DQUOTE);
	else if (c == '\\')
		prompt(NEXTCMD);
	return ((int)c);
}
