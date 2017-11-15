//
// Created by Alexandre ROULIN on 10/30/17.
//

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