/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:56:07 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/24 17:34:43 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		shell(void)
{
	add_hash("Alexandre", "@aroulin", 42);
	add_hash("Gregoire", "@gbourson", 42);
	add_hash("Jefferson", "@jle-quel", 42);
	hash_print();
	read_stdin();
	var_return(0);
	read_stdin();
	reset_signal();
	return (1);
}
