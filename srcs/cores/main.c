/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:25:44 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/20 01:30:04 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			main(void)
{
//	fd_log = open("./log", O_RDWR | O_TRUNC | O_CREAT, 0644);
	fd_log = -1;
	dprintf(fd_log, "√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√\n");
	dprintf(fd_log, "√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√\n");
	dprintf(fd_log, "√√√√√√√√√√√√√√√√√√ Welcome to 42sh bruuuh √√√√√√√√√√√√√√√√√√\n");
	dprintf(fd_log, "√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√\n");
	dprintf(fd_log, "√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√√\n");
	init_env();
	init_term();
	write_history_in_sh(get_str_from_history());
	init_signal();
	init_pwd(env_table(NULL, ENV_REC));
	shell();
	b_write_history_in_file(get_str_from_history());
	return (0);
}
