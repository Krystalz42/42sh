/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:06:50 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/23 20:05:10 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					convert_to_hist(char *buff)
{
	static t_read		*read_std;
	static int			cmd_len;
	int					i;

	if (((i = -1) && !buff) || cmd_len == 500)
		return (0);
	if (!read_std)
	{
		cmd_len = 0;
		read_std = init_struct_for_read();
		read_std->history = 1;
	}
	while (buff[++i])
		if (ft_isprint(buff[i]) && ++cmd_len)
			key_print_fct(read_std->cmd, buff[i]);
	if (check_cmd(&read_std) && ++cmd_len)
		return (0);
	else
	{
		cmd_len = 0;
		key_print_fct(read_std->cmd, 10);
		make_list_hist(read_std);
		read_std = NULL;
		return (1);
	}
}

void				write_history_in_sh(void)
{
	char		*path_hist;
	int			fd;
	char		*buff;
	int			command;

	if (!(path_hist = get_str_from_history()))
		return ;
	if ((fd = open(path_hist, O_RDONLY)) == -1)
	{
		free(path_hist);
		return ;
	}
	command = 0;
	buff = NULL;
	while (command < HISTSIZE && my_gnl(fd, &buff))
	{
		command += convert_to_hist(buff);
		ft_memdel((void **)&buff);
	}
	free(path_hist);
	close(fd);
}
