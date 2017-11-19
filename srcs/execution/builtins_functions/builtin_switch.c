/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_switch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:22:55 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 16:15:43 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t		error_msg(char *from, char *error, char *args)
{
	ft_putstr_fd(from, STDERR_FILENO);
	ft_putstr_fd(error, STDERR_FILENO);
	ft_putstr_fd(args, STDERR_FILENO);
	ft_putchar_fd(10, STDERR_FILENO);
	return (var_return(1));
}



uint8_t		builtin_foreground(t_node *node, int info)
{
	(void)node;
	(void)info;
		return (error_msg(FG, INVALID, node->content->command[1]));
}

uint8_t		builtin_background(t_node *node, int info)
{
	(void)info;
	(void)node;
	return (error_msg(FG, INVALID, node->content->command[1]));
}
