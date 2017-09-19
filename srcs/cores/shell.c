/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:56:07 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 21:06:53 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int		shell(void)
{
	add_hash("ls", "/bin/ls", 1);
	add_hash("grep", "/usr/bin/grep", 1);
	add_hash("mkdir", "/bin/mkdir", 1);
	search_path("ls");
	search_path("ls");
	search_path("ls");
	search_path("ls");
	search_path("ls");
	search_path("ls");
	search_path("ls");
	search_path("ls");
	search_path("mkdir");
	search_path("mkdir");
	search_path("mkdir");
	search_path("mkdir");
	search_path("mkdir");
	search_path("mkdir");
	search_path("grep");
	search_path("ls");
	hash_print();
    hash_reset();
    hash_print();
    add_hash("mkdir", "/bin/mkdir", 1);
    search_path("mkdir");
    search_path("mkdir");
    search_path("mkdir");
    hash_print();
    hash_reset();
    hash_reset();
    hash_reset();
    hash_reset();
    hash_reset();
    hash_print();
    hash_reset();
    hash_reset();
    hash_reset();
    hash_reset();

	read_stdin();
    write_history();
	return (1);
}
