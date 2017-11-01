//
// Created by Jefferson LE QUELLEC on 10/13/17.
//

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

size_t			get_length(const char *input, unsigned int index, char c)
{
	while (input[index])
	{
		if (input[index] != c)
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
		length = get_length(node->input, 0, ' ');
		temp = ft_strsplit(node->input, ' ');
		rest = temp[1] ? node->input + (length + ft_strlen(temp[0])) : NULL;
		arraydel(&temp);
	}
	return (rest);
}

static void		remove_rest(t_parsing *node, char *rest)
{
	char    *new;

	if (node)
	{
		new = ft_strsub(node->input, 0, ft_strlen(node->input) - ft_strlen(rest));
		ft_memdel((void**)&node->input);
		node->input = new;
	}
}

static void		add_rest(char **input, char **argv)
{
	char    *memory;

	memory = *input;
	*input = ft_strjoin(*input, *argv);
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
		if (*temp->input == '>' || ft_isdigit(*temp->input) == 1)
			get_argv(temp->next, &argv);
		else if (chk(*temp->input) == true)
			add_rest(&temp->next->input, &argv);
		else if (!temp->prev)
			add_rest(&temp->input, &argv);
		temp = temp->prev;
	}
}

