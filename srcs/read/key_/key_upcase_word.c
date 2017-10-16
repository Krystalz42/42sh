//
// Created by Alexandre ROULIN on 10/16/17.
//

#include <sh.h>

int				key_upcase_word(t_read **read_std, unsigned long buff)
{
	t_cmd		*tmp;

	tmp = (*read_std)->cmd;
	add_outstanding(NULL, buff, 0);
	while (tmp->c && tmp->c == 32)
		tmp = tmp->next;
	while (tmp->c && ft_isalnum(tmp->c))
	{
		if (ft_islower(tmp->c))
			tmp->c -= 32;
		tmp = tmp->next;
	}
	(*read_std)->print = 2;
	return (1);
}