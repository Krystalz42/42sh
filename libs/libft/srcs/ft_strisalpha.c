/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisalpha.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:19:22 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/17 17:19:26 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_strisalpha(char *string)
{
	size_t		index;

	if (!string || (*string) == '\0')
		return (0);
	index = 0;
	while (string[index])
	{
		if (ft_isalpha(string[index]) == 0)
			return (0);
		index++;
	}
	return (1);
}
