/* **********************************
 * **************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:56:07 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/29 16:34:46 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		shell(void)
{
	char		*input;
	t_parsing	*parse_struct;
	char 		**command;
	char 		**env;
	
	add_hash("    El patron  del job control   ", "    Je suis Alexandre", 42);
	add_hash("    Je rm -rf mon 21sh OKLM  && jsuis content parceque je fais un cat << EOF  ", "    Je suis Jefferson", 42);
	add_hash("    Mon 21sh marche pas && du coup je le fais en group   ", "    Je suis Gregoire", 42);
	add_hash("    Je suis malade et je parle avec un chatbot   ", "    Je suis Sofiane", 42);
	builtin_hash((char *[]){"hash", "------", "-eqweqw q-ewq-e-qw", NULL}, NULL);
	
	while (42)
	{
		if (!(input = read_stdin(DEFAULT)))
			continue ;
		command = ft_strsplit(input, 32);
		env = builtin_env(command);
		check_if_builtin(command , env);
		ft_memdel_tab(&(env));
		ft_memdel_tab(&(command));
		if (!(parse_struct = parsing(input)))
			continue ;
		ft_strdel(&input);
		lstdel(&parse_struct);
	}
}
