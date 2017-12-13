/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_builtins3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 17:17:54 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/13 15:50:11 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

/*
******************* PUBLIC *****************************************************
*/

uint8_t				usage_alias(void)
{
	ft_putstr_fd("Configuration\t\t\t\t\t: To create your own configuration of \
alias, and use it inside the shell,\n\t\t\t\t\t\tcreate (if not already \
created) a `.42sh_rc` inside your HOME,\n\t\t\t\t\t\tthen add your alias like \
`ls=ls -G` followed by a newline.\n", STDERR_FILENO);
	ft_putstr_fd("Usage\t\t\t\t\t\t: alias [variable=value]\n",
			STDERR_FILENO);
	ft_putstr_fd("-c                      \
			: Clear the alias list.\n", STDERR_FILENO);
	ft_putstr_fd("-r [pathname]           \
			: Read the alias file and append its contents to the \
alias list.\n", STDERR_FILENO);
	ft_putstr_fd("-w [pathname]           \
			: Write out the current alias list to the alias file.\n",
			STDERR_FILENO);
	ft_putstr_fd("otherwise               \
			: Print alias list\n", STDERR_FILENO);
	return (0);
}
