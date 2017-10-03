/* **********************************
 * **************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:56:07 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/29 16:34:46 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		shell(void)
{
	add_hash("    El patron    ", "    Je suis Alexandre", 42);
	add_hash("    Je rm -rf mon 21sh OKLM    ", "    Je suis Jefferson", 42);
	add_hash("    Mon 21sh marche pas    ", "    Je suis Gregoire", 42);
	add_hash("    Je suis malade    ", "    Je suis Sofiane", 42);
	add_hash("    Je suis pas la    ", "    Je suis Didier", 42);
	add_hash("    Je segfault sans stress    ", "    Je suis le rebeu", 42);
	hash_print(STDOUT_FILENO);
	manage_env("---------------i--------------u-----------", NULL);
	read_stdin();
	var_return(0);
	read_stdin();
	reset_signal();
	return (1);
}
