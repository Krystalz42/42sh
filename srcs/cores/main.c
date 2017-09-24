/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:25:44 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 17:57:30 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		main(void)
{
	init_env();
	fdb = open("./logger", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	write_history_in_sh();
	init_hash();
	if (init_term())
		return (1);
	var_return(1);
	create_table_env();
	shell();
	b_write_history_in_file(get_str_from_history());
	return (0);
}
