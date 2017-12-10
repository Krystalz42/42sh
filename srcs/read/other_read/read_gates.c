/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_gates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:32:10 by gbourson          #+#    #+#             */
/*   Updated: 2017/11/17 16:33:31 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			initialize_fct(t_read **read_std, unsigned char flags)
{
	(*read_std) = init_struct_for_read();
	(*read_std)->print = 2;
	init_prompt();
	init_signal();
	set_termios(SET_OUR_TERM);
	(*read_std)->cur = prompt(flags | PRINT);
	signal_reception(0);
	get_os_pointer(NULL, 1);
}

t_cmd			*finitialize_fct(t_read **read_std)
{
	set_termios(SET_OLD_TERM);
	return (finish_read_std(read_std));

}
