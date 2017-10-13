//
// Created by Jefferson LE QUELLEC on 10/13/17.
//

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static size_t	chk(char *str)
{
	size_t		occurence;
	size_t		length;

	occurence = 0;
	length = ft_strlen(str) - 1;

	while (str[length])
	{
		if (ft_isdigit(str[length]) == 1)
			occurence++;
		else
			break ;
		length--;
	}

	return (occurence);
}

static void		do_reconversion(char **old, char **node, size_t occurence)
{
	size_t		length;
	char		*old_memory;
	char		*node_memory;

	length = ft_strlen(*old) - occurence;
	old_memory = *old;
	*old = ft_strsub(*old, 0, length);

	node_memory = *node;
	*node = ft_strjoin(old_memory + length, *node);
	ft_memdel((void**)&old_memory);
	ft_memdel((void**)&node_memory);
}

/*
*************** PUBLIC *********************************************************
*/

void			stds(t_parsing *node)
{
	t_parsing	*old;
	size_t	nb;

	while (node)
	{
		old = node;
		node = node->next;
		if (node && node->str[0] == '>')
		{
			nb = chk(old->str);
			nb > 0 ? do_reconversion(&old->str, &node->str, nb) : 0;
		}
	}
}

