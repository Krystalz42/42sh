/* ************************************************************************** */
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
	add_hash("Alexandre", "@aroulin", 42);
	add_hash("Gregoire", "@gbourson", 42);
	add_hash("Jefferson", "@jle-quel", 42);
	add_hash("Sofiane", "@sbelazou", 42);
	hash_print(STDOUT_FILENO);
	read_stdin();
	read_stdin();
	reset_signal();
	return (1);
}
