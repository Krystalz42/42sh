//
// Created by Alexandre ROULIN on 10/13/17.
//

#include <sh.h>

t_parsing	*parsing(char *str)
{
	t_parsing	*new;

	new = NULL;
	lexing(&new, str);
	last(&new);
	operaters(&new);
	commands(&new);
	stds(new);
	redirections(&new);
	new->env = NULL;
	return (new);
}
