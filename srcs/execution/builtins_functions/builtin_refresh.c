/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_varenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:14:26 by sbelazou          #+#    #+#             */
/*   Updated: 2017/11/18 11:47:08 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char		*add_envar(char *var, char *value)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * (ft_strlen(var) + ft_strlen(value)) + 2)))
		return (NULL);
	str = ft_strcpy(str, var);
	str = ft_strcat(str, value);
	return (str);
}
