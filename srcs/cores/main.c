/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/21 18:25:44 by aroulin           #+#    #+#             */
/*   Updated: 2017/12/04 13:16:48 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			main(void)
{
	int integer = 42;
	void *varAcceptAll = (void *)&integer;
	printf("%d\n", *(int *)varAcceptAll);
	char character = '%';
	varAcceptAll = (void *)&character;
	printf("%c\n", *(char *)varAcceptAll);
	char *string = "As tu tester mon 42sh ?";
	varAcceptAll = (void *)string;
	printf("%s\n", (char *)varAcceptAll);

	fdb = open("/Users/aroulin/log", O_CREAT | O_TRUNC, O_RDWR, 0644);
	init_env();
	init_term();
	read_rc(NULL, INIT);
	write_history_in_sh(get_str_from_history());
	init_pwd(env_table(NULL, ENV_REC));
	shell();
	b_write_history_in_file(get_str_from_history());
	return (0);
}
