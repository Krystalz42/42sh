//
// Created by Jefferson LE QUELLEC on 10/13/17.
//

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

size_t			get_length(const char *str, unsigned int index, char c)
{
	while (str[index])
	{
		if (str[index] != c)
			break ;
		index++;
	}
	return (index);
}

static bool		chk(char c)
{
	short 					index;
	static const char       chk[4] = {'<', ';', '|', '\0'};

	index = 0;
	while (chk[index])
	{
		if (c == chk[index])
			return (true);
		index++;
	}
	return (false);
}

static char		*get_rest(t_parsing *node)
{
	size_t		length;
	char		**temp;
	char		*rest;

	rest = NULL;
	if (node)
	{
		length = get_length(node->str, 0, ' ');
		temp = ft_strsplit(node->str, ' ');
		rest = temp[1] ? node->str + (length + ft_strlen(temp[0])) : NULL;
		arraydel(&temp);
	}
	return (rest);
}

static void		remove_rest(t_parsing *node, char *rest)
{
	char    *new;

	if (node)
	{
		new = ft_strsub(node->str, 0, ft_strlen(node->str) - ft_strlen(rest));
		ft_memdel((void**)&node->str);
		node->str = new;
	}
}

static void		add_rest(char **str, char **argv)
{
	char    *memory;

	memory = *str;
	*str = ft_strjoin(*str, *argv);
	ft_memdel((void**)&memory);
	ft_memdel((void**)argv);
}

static void		get_argv(t_parsing *node, char **argv)
{
	char 	*rest;
	char 	*memory;

	rest = get_rest(node);
	memory = *argv;
	*argv = ft_strjoin(rest, *argv);
	remove_rest(node, rest);
	ft_memdel((void**)&memory);
}

/*
*************** PUBLIC *********************************************************
*/

void			redirections(t_parsing **node)
{
	t_parsing  *temp;
	char    *argv;

	temp = *node;
	argv = NULL;

	ptrnext(&temp, lstlen(temp));
	while (temp)
	{
		if (*temp->str == '>' || ft_isdigit(*temp->str) == 1)
			get_argv(temp->next, &argv);
		else if (chk(*temp->str) == true)
			add_rest(&temp->next->str, &argv);
		else if (!temp->prev)
			add_rest(&temp->str, &argv);
		temp = temp->prev;
	}
}

