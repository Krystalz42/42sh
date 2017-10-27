/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/10/24 15:37:54 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static int			check_env(char *str, char **env)
{
  unsigned int		i;
  unsigned int		size;

  i = 0;
  while (str[i])
    {
      str[i] = str[i + 1];
      i++;
    }
  str[i] = 0;
  size = (unsigned int)ft_strlen(str);
  while (env[i])
    {
      if (!(ft_strncmp(str, env[i], size)) && env[i][size] == '=')
	{
	  while (env[i][++size])
	    ft_putchar(env[i][size]);
	  return (0);
	}
      i++;
    }
  return (0);
}

static int			print_echo(char *str, char **env)
{
  unsigned int		i;

  i = 0;
  if (str[i] && str[i] == '$' && str[i + 1])
    return (check_env(str, env));
  while (str[i])
    {
      if (str[i] == '\\' && str[i + 1])
	{
	  if (str[i + 1] == 'c')
	    return (1);
	  else if (str[i + 1] == 'n')
	    {
	      ft_putchar('\n');
	      i++;
	    }
	  else
	    ft_putchar(str[i]);
	}
      else
	ft_putchar(str[i]);
      i++;
    }
  return (0);
}

uint8_t				ft_echo(char **command, char **env)
{
	unsigned char	n;
	unsigned int	i;

	i = 1;
	n = 0;
	if (tablen(command) != 1)
	  while (command[i])
	    {
	      if (!ft_strcmp(command[i], "-n") && i == 1)
		n++;
	      else
		{
		  if (i >= 2)
		    if (!(i == 2 && n))
		      ft_putchar(' ');
		  if (print_echo(command[i], env))
		    RETVAR(0);
		}
	      i++;
	    }
	if (!n)
	  ft_putchar('\n');
	RETVAR(0);
}
