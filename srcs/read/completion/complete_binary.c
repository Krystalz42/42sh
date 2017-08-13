/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:09:28 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/13 04:46:11 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void		complete_binary(t_read **read_std)
{
	char		*path;
	char		*tmp;

	(void)read_std;
	if (!(tmp = ft_strjoin(path, "/.42sh_hashtable")))
		return ;
	if (!(path = my_getenv("HOME")))
		return ;
	if (open(path, O_RDONLY | O_CREAT, S_IRUSR) < 0)
	{
		ft_strdel(&tmp);
		return ;
	}
	ft_strdel(&tmp);
}
