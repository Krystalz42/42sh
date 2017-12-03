/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:25:44 by aroulin           #+#    #+#             */
/*   Updated: 2017/12/03 12:48:23 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			main(void)
{
	fdb = open("/Users/aroulin/log", O_CREAT | O_TRUNC, O_RDWR, 0644);
	init_env();
	init_term();
	read_rc(".42sh_rc");
	write_history_in_sh(get_str_from_history());
	init_pwd(env_table(NULL, ENV_REC));
	shell();
	b_write_history_in_file(get_str_from_history());
	return (0);
}
