/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:17:56 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 17:18:04 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strisdigit(char *string)
{
	size_t		index;

	if (string == NULL || (*string) == '\0')
		return (0);
	index = 0;
	while (string[index])
	{
		if (ft_isdigit(string[index]) == 0 && string[index] != '-')
			return (0);
		index++;
	}
	return (1);
}
