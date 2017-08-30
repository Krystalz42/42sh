/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <libft.h>

char	*if_color(char *color)
{
	if (!ft_ustrncmp(color, "{RED}", 5))
		return (RED);
	if (!ft_ustrncmp(color, "{BLU}", 5))
		return (BLU);
	if (!ft_ustrncmp(color, "{CYN}", 5))
		return (CYN);
	if (!ft_ustrncmp(color, "{GRN}", 5))
		return (GRN);
	if (!ft_ustrncmp(color, "{YEL}", 5))
		return (YEL);
	if (!ft_ustrncmp(color, "{MAG}", 5))
		return (MAG);
	if (!ft_ustrncmp(color, "{WHT}", 5))
		return (WHT);
	if (!ft_ustrncmp(color, "{RST}", 5))
		return (RST);
	return (NULL);
}
