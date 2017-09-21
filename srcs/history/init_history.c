/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:06:50 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/19 20:22:28 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		convert_to_hist(char *buff)
{
	static t_read	*read_std;
	int				i;
	static int		cmd;

	i = -1;
	if (!(cmd <= HISTSIZE) || !buff)
		return ;
	if (!read_std)
		read_std = init_struct_for_read();
	while (buff[++i])
		key_print_(&read_std, buff[i]);
	if (!check_cmd(&read_std))
	{
		read_std->history = 1;
		make_list_hist(read_std);
		read_std = NULL;
		cmd++;
	}
}

void			init_history(void)
{
	char		*path_hist;
	int			fd;
	char		*buff;

	if (!(path_hist = get_str_from_history()))
		return ;
	if ((fd = open(path_hist, O_RDONLY)) == -1)
	{
		free(path_hist);
		return ;
	}
	while (my_gnl(fd, &buff))
	{
		convert_to_hist(buff);
		free(buff);
	}
    free(path_hist);
	close(fd);
}
