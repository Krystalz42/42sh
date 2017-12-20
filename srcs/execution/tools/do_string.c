/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:41:16 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/20 14:41:18 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			do_string(t_parsing *node)
{
	int					fildes;
	char				*temp;

	temp = ft_itoa(time(NULL));
	node->heredoc = ft_strjoin("/tmp/", temp);
	fildes = open(node->heredoc, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_memdel((void **)&temp);
	ft_putendl_fd(node->next->command[0], fildes);
	close(fildes);
}
