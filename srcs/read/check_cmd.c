/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 21:05:29 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 21:02:47 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static inline int 	is_quote(char cmd)
{
	static const char		*buff;
	int						i;

	i = -1;
	buff = "\'\"";
	while (++i < 2)
		if (cmd == buff[i])
			return (1);
	return (0);
}

static inline int	launch_rec(char cmd,char c)
{
	if (is_quote(cmd) && !is_quote(c))
		return (1);
	return (0);
}

static inline int 	stop_rec(char cmd, char c)
{
	if (is_quote(c) && is_quote(cmd) && cmd == c)
		return (1);
	return (0);
}

char				rec_brackets(t_cmd *cmd, char c)
{

	if (cmd == NULL)
		return (!c ? '\\' : c);
	if (cmd->c == '\\')
		return (rec_brackets(cmd->next->next, c));
	if (launch_rec(cmd->c, c))
		return (rec_brackets(cmd->next, cmd->c));
	if (stop_rec(cmd->c, c))
		return (rec_brackets(cmd->next, '\0'));
	if (cmd->c)
		return (rec_brackets(cmd->next, c));
	return (c);
}

int			check_cmd(t_read **read_std)
{
	t_cmd		*tmp;
	char		c;

	tmp = first_cmd((*read_std)->cmd, 1);
	c = rec_brackets(tmp, '\0');
	if (c == '\'')
		prompt(QUOTE);
	else if (c == '\"')
		prompt(DQUOTE);
	else if (c == '\\')
		prompt(NEXTCMD);
	return ((int)c);
}
