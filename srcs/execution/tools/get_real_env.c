/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_real_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:15:03 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 15:15:08 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char			**get_real_env(t_node *node)
{
	if (node->content->env_option)
		return (node->content->env);
	else
		return (env_table(NULL, ENV_REC));
}
