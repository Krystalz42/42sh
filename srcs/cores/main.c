/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:25:44 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/09 14:57:56 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			main(void)
{
	logger_init(7, "log");
	init_env();
	init_term();


	write_history_in_sh(get_str_from_history());
	log_success(" Welcome to the new command !");
	init_signal();
	log_success(" Welcome to the new command !");
	init_pwd(env_table(NULL, ENV_REC));
	log_success(" Welcome to the new command !");
	shell();
	log_success(" Welcome to the new command !");
	b_write_history_in_file(get_str_from_history());
	log_success(" Welcome to the new command !");
	logger_close();
	log_success(" Welcome to the new command !");
	return (0);
}

