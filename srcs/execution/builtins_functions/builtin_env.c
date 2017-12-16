/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:21:59 by aroulin           #+#    #+#             */
/*   Updated: 2017/12/01 14:36:14 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t			fct(t_parsing *node, int info)
{
	if (node->command[0])
	{
		node->env_option = 1;
		if (check_if_builtin(node, DONT_EXECUTE) == -1)
			if ((looking_for_path(&node->command[0])) == 0)
				collect_path(&node->command[0]);
		execute_node(node, NULL, info);
	}
	else
	{
		node->env_option = 1;
		ft_putstrtab(node->env, 10);
		var_return(0);
	}
	return (1);
}

int				free_command(char ***command, int ret)
{
	char		**t;
	int			index;

	t = (char **)ft_memalloc(sizeof(char *) * (ft_tablen(*command) - ret + 1));
	index = 0;
	while (index < ret)
	{
		ft_memdel((void **)&(*command)[index]);
		index++;
	}
	index = 0;
	while ((*command)[ret + index])
	{
		t[index] = (*command)[ret + index];
		index++;
	}
	ft_memdel((void **)&(*command));
	*command = t;
	return (1);
}

uint8_t			check_option(t_parsing *node, int info, int opt)
{
	int			ret;
	char		**env;

	node->env = node->env_option ?
								node->env : env_table(NULL, ENV_REC);
	env = node->env_option ? node->env : NULL;
	if (opt == 'i' &&
	(ret = start_from_null(node->command, &node->env)) >= 0)
		free_command(&(node->command), ret) && fct(node, info);
	if (opt == 'u' &&
	(ret = start_from_less(node->command, &node->env)) >= 0)
		free_command(&(node->command), ret) && fct(node, info);
	if (opt == 0 &&
	(ret = start_from_full(node->command, &node->env)) >= 0)
		free_command(&(node->command), ret) && fct(node, info);
	ft_memdel_tab(&env);
	return (0);
}

uint8_t			builtin_env(t_parsing *node, int info)
{
	int				index;
	int				opt;
	int				table;

	table = 0;
	opt = 0;
	if (ft_strcmp(node->command[1], HELP) == 0)
		return (usage_env());
	while (node->command[++table] &&
			node->command[table][0] == '-' && !(index = 0))
	{
		while (node->command[table][index])
		{
			if (potential_option("-iu",
			node->command[table][index]) == 0)
				return (error_msg(ENV, BAD_OPTION,
							node->command[table] + index));
				if (node->command[table][index] == 'u' ||
					node->command[table][index] == 'i')
				opt = node->command[table][index];
			index++;
		}
	}
	free_command(&node->command, table);
	return (check_option(node, info, opt));
}
