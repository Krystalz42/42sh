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
	fdb = open("./logger", O_TRUNC | O_WRONLY, 0000);
	errno = ENOMEM;
		perror("");
	init_env();
	write_history_in_sh();
	init_hash();
	if (init_term())
		return (1);
	var_return(1);
	create_table_env();
	init_fd();
	shell();
	b_write_history_in_file(get_str_from_history());
	return (0);
}
