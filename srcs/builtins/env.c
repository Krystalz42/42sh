/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 17:00:50 by gbourson          #+#    #+#             */
/*   Updated: 2017/09/25 18:27:06 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

// typedef struct		s_env_n
// {
// 	char			*value;
// 	struct s_env	*next;
// }					t_env_n;

t_env_n         *env_new_lst(char *content)
{
    t_env_n *lst;

    lst = NULL;
    lst = ft_memalloc(sizeof(t_env_n));
    if (content && lst)
    {
        lst->value = ft_strdup(content);
        lst->next = NULL;
        return (lst);
    }
    return (NULL);
}

void	        ft_envadd_back(t_env_n **alst, t_env_n *new)
{
	t_env_n *tmp;

	t_env_n = *alst;
	if (tmp == NULL)
		*alst = new;
	else if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_env_n         *_env_cpy(char *line)
{
    extern char	    **environ;
    t_env_n         *env_lst;
    int i;

    i = 0;
    env_lst = NULL;
    if(!environ)
        return (NULL);
    while (environ[i])
    {
        ft_envadd_back(&env_lst, env_new_lst(environ[i]));
        i++;
    }
    return (lst)
}

int             _env(char *line)
{
    t_env_n     *env_cpy;

    
    (void)line;
    return (0);
}