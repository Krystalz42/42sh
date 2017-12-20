/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:21:52 by aroulin           #+#    #+#             */
/*   Updated: 2017/12/20 14:39:25 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmd		*read_stdin_no_tty(void)
{
	t_cmd				*cmd;
	static ssize_t		ret;
	char				buff;

	if (ret == EOF)
		exit_();
	cmd = create_element('\0');
	while ((ret = read(STDIN_FILENO, &buff, sizeof(char))) > 0)
	{
		if (ft_iscrlf(buff) || ret == -1)
			return (first_cmd(cmd, 1));
		else if (ft_isprint(buff))
			key_print_fct(cmd, buff);
	}
	ret = ret == 0 ? -1 : ret;
	return (first_cmd(cmd, 1));
}

t_cmd		*read_input(unsigned char flags)
{
	if (*shell_interectative())
	{
		return (read_stdin(flags));
	}
	else
	{
		return (read_stdin_no_tty());
	}
}
