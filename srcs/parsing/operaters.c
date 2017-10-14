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

static bool		chk(char *str)
{
	size_t				index;
	static const char	*operaters[] = {";", "|", "<", "<<", ">", ">>", ">&", "<&", ">>&", NULL};

	index = 0;
	while (operaters[index])
	{
		if (ft_strcmp(str, operaters[index]) == 0)
			return (true);
		index++;
	}
	return (false);
}

/*
*************** PUBLIC *********************************************************
*/

void			operaters(t_parsing **node)
{
	size_t	index;
	char	err;
	t_parsing	*temp;

	index = 0;
	temp = *node;

	while (temp)
	{
		if (index % 2 == 1)
		{
			err = chk(temp->str);
			if (err == false)
			{
				error(temp->str, node);
				return;
			}
		}
		index++;
		temp = temp->next;
	}
}
