//
// Created by Jefferson LE QUELLEC on 10/13/17.
//

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static void		error(t_parsing **node)
{
	ft_putendl_fd("21sh: syntax not respected", 2);
	lstdel(node);
}

static bool		chk(const char *str)
{
	size_t	index;
	size_t	flag;

	index = 0;
	flag = 0;
	while (str[index])
	{
		if (str[index] == ' ')
			flag++;
		index++;
	}
	return index == flag ? false : true;
}

/*
*************** PUBLIC *********************************************************
*/

void			commands(t_parsing **node)
{
	size_t	index;
	char	err;
	t_parsing	*temp;

	index = 0;
	temp = *node;

	while (temp)
	{
		if (index % 2 == 0)
		{
			err = chk(temp->str);
			if (err == false)
			{
				error(node);
				return ;
			}
		}
		index++;
		temp = temp->next;
	}
}
