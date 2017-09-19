/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:06:50 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/06 18:44:37 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int		convert_to_hist(char *buff, int ret)
{
	static t_read	*read_std;
	static int		i;
	static int		cmd;

	i = -1;
	while (i < ret - 1 && ++cmd <= 500)
	{
		read_std = init_struct_for_read();
		while (++i < ret)
		{
			if (buff[i] == 10 && !check_cmd(&read_std))
				break ;
			else
				key_print_(&read_std, buff[i]);

		}
		read_std->history = 1;
		make_list_hist(read_std);
		read_std = NULL;
	}
	return (cmd == 500 ? 0 : 1);
}

void			init_history(void)
{
	char		*home;
	char		*path_hist;
	int			fd;
	char		buff[100000];
	int			ret;

	if (!(home = my_getenv("HOME"))) {
		return ;
	}
	path_hist = ft_strjoin(home, "/.42sh_history");
	if ((fd = open(path_hist, O_RDONLY | O_CREAT, S_IRUSR)) == -1)
		return ;
	ft_bzero(buff, 10000);
	while ((ret = read(fd, &buff, sizeof(char) * 10000)))
		if (!convert_to_hist(buff, ret))
			break ;
	remove(path_hist);
	free(path_hist);
	close(fd);
}
