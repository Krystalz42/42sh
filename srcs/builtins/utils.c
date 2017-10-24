/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:47:33 by sbelazou          #+#    #+#             */
/*   Updated: 2017/10/24 15:41:38 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

unsigned int		tablen(char **src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
		i++;
	return (i);
}

char				**env_cpy(char **src)
{
	unsigned int	i;
	char			**cpy;

	if (!(cpy = malloc(sizeof(char *) * (tablen(src) + 1))))
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = ft_strdup(src[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

char				**init_pwd(char **env)
{
	char			buff[UCHAR_MAX];
	int				i;

	i = 0;
	if (getcwd(buff, UCHAR_MAX) == NULL)
		return (env);
	if (search_in_tab(env, "PWD=") == -1)
	{
		i = tablen(env);
		env[i++] = add_envar("PWD=", buff);
		env[i] = NULL;
		b_data()->pwd = ft_strdup(buff);
	}
	else
		b_data()->pwd = ft_strdup(buff);
	if (search_in_tab(env, "OLDPWD=") == -1)
	{
		i = tablen(env);
		env[i++] = add_envar("OLDPWD", "=");
		env[i] = NULL;
	}
	b_data()->oldpwd = NULL;
	return (env);
}

signed int			search_in_tab(char **data, char *var)
{
	signed int		i;

	i = 0;
	while (data[i])
	{
		if (ft_strncmp(data[i], var, ft_strlen(var)) == 0)
			return (i);
		i++;
	}
	return (-1);
}

/*
int		main(int ac, char **av, char **env)
{
  char		**e;
  char		**tab;

  tab = malloc(1000);
  tab[0] = ft_strdup("echo");
  //tab[1] = ft_strdup(av[1]);
  //tab[] = ft_strdup("");
  tab[1] = 0;
  if (!(e = env_cpy(env)))
    return (1);
  e = init_pwd(e);
  //ft_aff_tab(e, "\n");
  ft_echo(av, e);
  ft_echo(av, e);
  ft_echo(av, e);
  //e = refresh_varenv(e);
  //ft_putendl("\n------------------------\n\n");
  //ft_aff_tab(e, "\n");
  while (1)
	  ;
  return (0);
  }*/
