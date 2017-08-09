/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:26:22 by jgraille          #+#    #+#             */
/*   Updated: 2016/12/09 15:33:10 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countchar(char const *s, char c)
{
	int		count;

	count = 0;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			count++;
		s++;
	}
	return (count);
}
