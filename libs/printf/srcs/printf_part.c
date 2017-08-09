/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:33:20 by jgraille          #+#    #+#             */
/*   Updated: 2017/04/18 17:28:50 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <ft_printf.h>
#include <libft.h>

static void		part_one(char **special, t_fmtid *id, va_list *ap)
{
	if (ft_strchr("bBoOxX", id->arg))
		*special = part_base(id, ap);
	if (ft_strchr("uU", id->arg))
		*special = part_unsigned(id, ap);
	if (ft_strchr("dDi", id->arg))
		*special = part_nu(*id, ap);
	if (ft_strchr("fFeE", id->arg))
		*special = part_dec(*id, ap);
	if (ft_strchr("sS", id->arg))
		*special = part_str(*id, ap);
}

size_t			str_special(t_fmtid id, va_list *ap)
{
	char		*special;
	size_t		len;

	id = detect_pre(id, ap);
	if (id.full_arg == NULL)
		special = ft_strdup("\0");
	if (id.arg == '<')
		special = ft_strdup(id.dif);
	part_one(&special, &id, ap);
	if (ft_strchr("cCpP%/", id.arg))
		special = part_extra(&id, ap);
	if (ft_strchr("cC/", id.arg) && id.dif != NULL && id.dif[0] == 'N')
	{
		clean_struct(&id);
		return (ft_strlen(special) + 1);
	}
	ft_putstr(special);
	len = ft_strlen(special);
	ft_memdel((void **)&special);
	clean_struct(&id);
	return (len);
}
