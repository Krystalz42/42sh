/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:25:44 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/29 16:44:27 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			main(void)
{
	g_fdb = open("/Users/aroulin/42sh/logger", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	logger_init(7, "log");
	init_env();
	write_history_in_sh();
	init_term();
	var_return(1);
	shell();
	b_write_history_in_file(get_str_from_history());
	return (0);
}