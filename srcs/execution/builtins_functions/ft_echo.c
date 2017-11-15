/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <sbelazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:36:39 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/15 17:28:10 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

// static int			check_env(char *str, char **env)
// {
// 	unsigned int		i;
// 	unsigned int		size;
//
// 	i = 0;
// 	while (str[i])
// 	{
// 		str[i] = str[i + 1];
// 		i++;
// 	}
// 	str[i] = 0;
// 	size = (unsigned int)ft_strlen(str);
// 	while (env[i])
// 	{
// 		if (!(ft_strncmp(str, env[i], size)) && env[i][size] == '=')
// 		{
// 			while (env[i][++size])
// 				ft_putchar(env[i][size]);
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

static int			print_echo(char *str, char **env __attribute__((unused)))
{
	unsigned int		i;

	i = 0;
	// if (str[i] && str[i] == '$' && str[i + 1])
	// 	return (check_env(str, env));
	while (str[i])
	{
		// if (str[i] == '\\' && str[i + 1])
		// {
		// 	if (str[i + 1] == 'c')
		// 		return (1);
		// 	else if (str[i + 1] == 'n')
		// 	{
		// 		ft_putchar('\n');
		// 		i++;
		// 	}
		// 	else
		// 		ft_putchar(str[i]);
		// }
		// else
			ft_putchar(str[i]);
		i++;
	}
	return (0);
}

uint8_t				ft_echo(t_node *node, int info)
{
	unsigned char	n;
	unsigned int	i;
	char			**env;

	(void)info;
	env = node->content->env_option ? node->content->env : env_table(NULL, ENV_REC);
	i = 1;
	n = 0;
	if (tablen(node->content->command) != 1)
		while (node->content->command[i])
		{
			if (!ft_strcmp(node->content->command[i], "-n") && i == 1)
				n++;
			else
			{
				if (i >= 2)
					if (!(i == 2 && n))
						ft_putchar(' ');
				if (print_echo(node->content->command[i], env))
					return (var_return(0));
			}
			i++;
		}
	if (!n)
		ft_putchar('\n');
	return (var_return(0));
}
//
// const t_echo	g_echo[] =
// {
// 	(t_echo){"-n", OPTION_N},
// 	(t_echo){"-e", OPTION_E}
// };
//
// /*
// *************** PRIVATE ********************************************************
// */
// //
// // static uint8_t	get_option(char **argv)
// // {
// // 	short		index;
// // 	uint8_t		status;
// //
// // 	status = DEFAULT;
// // 	while (argv && *argv)
// // 	{
// // 		index = 0;
// // 		while (index < 2)
// // 		{
// // 			if (!ft_strcmp(*argv, g_echo[index].str))
// // 				status |= g_echo[index].status;
// // 			index++;
// // 		}
// // 		argv++;
// // 	}
// // 	return (status);
// }
//
// while (ft_putst )
//
//
// /*
// *************** PUBLIC *********************************************************
// */
//
// uint8_t			ft_echo(t_node *node, int info __attribute__((unused)))
// {
// 	uint8_t		options;
// 	char		**argv;
//
// 	argv = node->content->command + 1;
// 	if (argv)
// 	{
// 		options = get_option(node->content->command + 1);
// 		do_echo(node->content->command + 1);
// 	}
// 	options & OPTION_N ? ft_putchar(10) : 0;
// 	else
// 	return (0);
// }
