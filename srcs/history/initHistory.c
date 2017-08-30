/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 19:06:50 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/24 16:43:33 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		convert_to_hist(char *buff, int ret)
{
	static t_read	*read_std;
	static int		i;

	i = -1;

	if (!buff)
		return ;
	if (read_std)
	{

	}
	else
	{
		while (i < ret - 1)
		{
			read_std = init_struct_for_read();
			while (buff[++i] && buff[i] != 10)
			{
				key_print_(&read_std, buff[i]);
			}
			read_std->history = 1;
			make_list_hist(read_std);
			read_std = NULL;
		}
	}

}

void		init_history(void)
{
	char		*home;
	char		*path_hist;
	int			fd;
	char		buff[100000];
	int			ret;

	ft_bzero(buff, 100000);
	if (!(home = my_getenv("HOME")))
		return ;
	path_hist = ft_strjoin(home, "/.42sh_history");
	if ((fd = open(path_hist, O_RDONLY | O_CREAT, S_IRUSR)) == -1)
		return ;
	if ((ret = read(fd, &buff, sizeof(char) * 100000)) > 0)
		convert_to_hist(buff, ret);
	if (ret == 100000)
		STR_FD("CA PAR EN COUILLE\n", fdb);
	remove(path_hist);
	free(path_hist);
	close(fd);
}
