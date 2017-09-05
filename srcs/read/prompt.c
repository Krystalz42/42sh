/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 14:22:37 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/05 18:17:28 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>



char			*init_prompt(void)
{
	char *str;
	int fd;

	if ((fd = open(".git/config", O_RDONLY)) == -1)
		;
	while (get_next_line(fd, &str))
	{
		if (!ft_strncmp(str, "[branch", 6))
		{
			close(fd);
			return (str);
		}
		else
			ft_strdel(&str);
	}
	close(fd);
	return (NULL);
}

int 			prompt(unsigned char flags, char *str)
{
	static char		*prompt;

	init_prompt();
	if (flags & HEREDOC)
		prompt = "heredoc > ";
	else if (flags & DQUOTE)
		prompt = "dquote > ";
	else if (flags & QUOTE)
		prompt = "quote > ";
	else if (flags & NEXTCMD)
		prompt = "nextcmd > ";
	else if (flags & DEFAULT)
		prompt = str;
	if (!(flags & PRINT))
		STR_FD(prompt, init_fd());
	return (ft_strlen(prompt));
}
