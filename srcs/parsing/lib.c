//
// Created by Jefferson LE QUELLEC on 10/13/17.
//

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

void			lstadd(t_parsing *node, t_parsing *new)
{
	while (node->next)
		node = node->next;
	node->next = new;
	new->prev = node;
}

/*
*************** PUBLIC *********************************************************
*/

void			lstnew(t_parsing **node, char *str)
{
	t_parsing *new;

	new = (t_parsing*)ft_memalloc(sizeof(t_parsing));
	new->str = ft_strdup(str);
	new->next = NULL;
	new->prev = NULL;

	if (*node == NULL)
		*node = new;
	else
		lstadd(*node, new);
}

void			lstdel(t_parsing **node)
{
	t_parsing	*memory;

	while (*node)
	{
		memory = *node;
		*node = (*node)->next;
		ft_memdel((void **)&memory->str);
		ft_memdel((void **) &memory);
	}
}

void			ptrnext(t_parsing **node, size_t stop)
{
	size_t	index;

	index = 0;
	if (*node)
	{
		while ((*node)->next)
		{
			if (index == stop)
				break ;
			*node = (*node)->next;
			index++;
		}
	}
}

size_t			lstlen(t_parsing *node)
{
	size_t	index;

	index = 0;
	while (node)
	{
		index++;
		node = node->next;
	}
	return (index);
}

void			arraydel(char ***array)
{
	size_t 		index;

	index = 0;
	if (*array)
	{
		while ((*array)[index])
		{
			ft_memdel((void **) &(*array)[index]);
			index++;
		}
		ft_memdel((void **) array);
	}
}