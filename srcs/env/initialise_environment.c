/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_environment.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:16:47 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/30 15:16:48 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int					check_from_local_env(char **env, char *var)
{
	int				index;

	index = 0;
	if (env)
		while (env[index])
		{
			if (compare_environment(var, env[index]))
				return (1);
			index++;
		}
	return (0);
}

int					start_from_full(char **command, char ***env)
{
	char		**cpy;
	int			index;
	int			index_env;
	int			index_cpy;

	index = 0;
	while (command[index] && ft_chrchar(command[index], '='))
		index++;
	cpy = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(*env) + index + 1));
	index_cpy = -1;
	index = 0;
	while (command[index] && ft_chrchar(command[index], '='))
	{
		if (check_from_local_env(cpy, command[index]) == 0)
			cpy[++index_cpy] = ft_strdup(command[index]);
		index++;
	}
	index_env = -1;
	while ((*env)[++index_env])
		if (check_from_local_env(cpy, (*env)[index_env]) == 0)
			cpy[++index_cpy] = ft_strdup((*env)[index_env]);
	cpy[++index_cpy] = NULL;
	(*env) = cpy;
	return (index);
}

int					start_from_less(char **command, char ***env)
{
	char		**cpy;
	int			index;
	int			index_cpy;

	if (*command)
	{
		if (check_from_local_env(*env, *command) == 0)
		{
			(*env) = env_table(NULL, ENV_CPY);
			return (1);
		}
		cpy = (char **)ft_memalloc(sizeof(char *) * ft_tablen(*env));
		index = 0;
		index_cpy = -1;
		while ((*env)[index])
		{
			if (compare_environment(*command, (*env)[index]) == 0)
				cpy[++index_cpy] = ft_strdup((*env)[index]);
			index++;
		}
		(*env) = cpy;
		return (1);
	}
	error_msg(ENV, NO_ARGS_U, NULL);
	return (-1);
}

int					start_from_null(char **command, char ***env)
{
	int			index;
	int			index_cpy;

	index = 0;
	while (command[index] && ft_chrchar(command[index], '='))
		index++;
	(*env) = (char **)ft_memalloc(sizeof(char *) * (index + 1));
	index = 0;
	index_cpy = 0;
	while (command[index] && ft_chrchar(command[index], '='))
	{
		log_trace("%d", check_from_local_env((*env), command[index]));
		if (check_from_local_env((*env), command[index]) == 0)
		{
			(*env)[index_cpy] = ft_strdup(command[index]);
			index_cpy++;
			(*env)[index_cpy] = NULL;
		}
		index++;
	}
	(*env)[index_cpy] = NULL;
	return (index);
}
