/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage_environment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 14:21:39 by aroulin           #+#    #+#             */
/*   Updated: 2017/10/04 14:21:40 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			usage_environement(char *string)
{
	STR_FD("42sh env: ", STDERR_FILENO);
	STR_FD(string, STDERR_FILENO);
	STR_FD("usage: env [-i] [-u name] [name=value]\n", STDERR_FILENO);
	return (0);
}