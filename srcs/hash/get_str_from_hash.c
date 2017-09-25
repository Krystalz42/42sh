/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_str_from_hash.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 19:47:50 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/25 17:38:40 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char		*get_str_from_hash(void)
{
	char	*home;

	if (!(home = my_getenv("HOME")))
		return (NULL);
	return (ft_strjoin(home, PATH_HASH));
}
