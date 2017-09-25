/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_builtins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:18:00 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/25 18:38:24 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

typedef	int	(*builtins_func)(char *line);

struct s_builtins_struct
{
    char            *b;
    builtins_func   f;
};

static const struct s_builtins_struct s_builtins_t[] = {
	{"env", _env},
	// {"setenv", _setenv},
	// {"unsetenv", _unsetenv},
	// {"echo", _echo},
	// {"cd", _cd},
	// {"exit", _exit},
	{NULL, NULL}
};

int builtins_match(char *line)
{
    char *c;
    int i;
    
    i = 0;
    ft_putendl("HELLO");
    while (s_builtins_t[i].b)
    {
        if(ft_strcmp(line, s_builtins_t[i].b) == 0)
            return (s_builtins_t[i].f(line));
        i++;
    }
    return (0);
}

int parse_builtins(char *line)
{
    
    if(builtins_match(line))
        return (1);
    else
    {
        ft_putendl("EXEC");
        return (0);
    }
}