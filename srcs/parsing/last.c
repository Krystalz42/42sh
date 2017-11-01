//
// Created by Jefferson LE QUELLEC on 10/13/17.
//

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static void		error(char *str, t_parsing **node)
{
	ft_putstr_fd("21sh: parse error near: ", 2);
	ft_putendl_fd(str, 2);
	lstdel(node);
	var_return(1);
}

static void		remove_last(t_parsing *node)
{
	t_parsing	*memory;

	memory = node;
	node = node->prev;
	node->next = NULL;

	ft_memdel((void**)&memory->input);
	ft_memdel((void**)&memory);
}

/*
*************** PUBLIC *********************************************************
*/

void			last(t_parsing **node)
{
	t_parsing  *temp;

	temp = *node;
	if (temp)
	{
		ptrnext(&temp, lstlen(temp));

		if (temp->input[0] == ';')
			remove_last(temp);
		else if (chk_operaters(*temp->input) == true)
			error(temp->input, node);
	}
}
