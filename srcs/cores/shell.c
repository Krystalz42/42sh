/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:56:07 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 21:06:53 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		shell(void)
{
	add_hash("Alexandre", "@aroulin", 42);
	add_hash("Gregoire", "@gbourson", 42);
	add_hash("Jefferson", "@jle-quel", 42);
	add_hash("Didier", "@dsebban", 42);
	hash_print();
	var_return(0);
	read_stdin();




	b_clear_history();
	convert_to_hist("CECI UN UN AJOUT");
	b_write_history_in_file(ft_strdup("./ici"));




	read_stdin();




	b_write_history_in_file(get_str_from_history());
	return (1);
}
