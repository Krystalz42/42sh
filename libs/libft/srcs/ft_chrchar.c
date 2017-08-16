/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:08:25 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/16 18:23:38 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_chrchar(char *str, char chr)
{
	int i;
	int c;

	c = 0;
	i = -1;
	while (str[++i])
		if (str[i] == chr)
			c++;
	return (c);
}
