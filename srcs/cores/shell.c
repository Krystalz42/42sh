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
	char 		**tmp;
	add_hash("    El patron    ", "    Je suis Alexandre", 42);
	add_hash("    Je rm -rf mon 21sh OKLM    ", "    Je suis Jefferson", 42);
	add_hash("    Mon 21sh marche pas    ", "    Je suis Gregoire", 42);
	add_hash("    Je suis malade    ", "    Je suis Sofiane", 42);
	builtin_hash((char *[]){"hash", "------", "-eqweqw q-ewq-e-qw", NULL}, NULL);
	while (42)
	{
		if (!(input = read_stdin(DEFAULT)))
			continue ;
		check_if_builtin((tmp = ft_strsplit(input, 32)), NULL);
		ft_memdel_tab(&(tmp));
		if (!(parse_struct = parsing(input)))
			continue ;
		lstdel(&parse_struct);
//		var_return(0);
	}
}
