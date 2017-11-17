/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:21:59 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/17 16:30:09 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

uint8_t			fct(t_node *node, int info)
{
	if (node->content->command[0])
	{
		node->content->env_option = 1;
		if (check_if_builtin(node, DONT_EXECUTE) == -1)
			if ((looking_for_path(&node->content->command[0])) == 0)
				collect_path(&node->content->command[0]);
		execute_node(node, NULL, info);
	}
	else
	{
		node->content->env_option = 1;
		ft_putstrtab(node->content->env, 10);
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

uint8_t			check_option(t_node *node, int info, int opt)
{
	int			ret;
	char		**env;

	node->content->env = node->content->env_option ?
								node->content->env : env_table(NULL, ENV_REC);
	env = node->content->env_option ? node->content->env : NULL;
	log_fatal("%d", opt);
	if (opt == 'i' &&
	(ret = start_from_null(node->content->command, &node->content->env)) >= 0)
		free_command(&(node->content->command), ret) && fct(node, info);
	if (opt == 'u' &&
	(ret = start_from_less(node->content->command, &node->content->env)) >= 0)
		free_command(&(node->content->command), ret) && fct(node, info);
	if (opt == 0 &&
	(ret = start_from_full(node->content->command, &node->content->env)) >= 0)
		free_command(&(node->content->command), ret) && fct(node, info);
	ft_memdel_tab(&env);
	return (0);
}

uint8_t			builtin_env(t_node *node, int info)
{
	int				index;
	int				opt;
	int				table;

	table = 0;
	opt = 0;
	if (ft_strcmp(node->content->command[1], HELP) == 0)
		return (var_return(usage_env()));
	while (node->content->command[++table] &&
			node->content->command[table][0] == '-' && !(index = 0))
	{
		while (node->content->command[table][index])
		{
			if (potential_option("-iu",
			node->content->command[table][index]) == 0)
				return (error_msg(ENV, BAD_OPTION,
										node->content->command[table] + index));
			if (node->content->command[table][index] == 'u' ||
									node->content->command[table][index] == 'i')
				opt = node->content->command[table][index];
			index++;
		}
	}
	free_command(&node->content->command, table);
	return (check_option(node, info, opt));
}
