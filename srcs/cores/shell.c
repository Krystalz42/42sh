/* **********************************
 * **************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:56:07 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/24 16:32:35 by sbelazou         ###   ########.fr       */
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

	input = NULL;
	parse_struct = NULL;
	command = NULL;
	env = NULL;
	while (42)
	{
		ft_strdel(&input);
		ft_memdel_tab(&(env));
		ft_memdel_tab(&(command));
		lstdel(&parse_struct);
		if (!(input = read_stdin(DEFAULT)))
			continue ;
		command = ft_strsplit(input, 32);
		//env = builtin_env(command);
		check_if_builtin(command, env_table(NULL, ENV_REC));
		log_error("Passage au parsing");
		if (!(parse_struct = parsing(input)))
			continue ;

	}
}
