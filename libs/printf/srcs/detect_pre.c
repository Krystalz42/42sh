/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_pre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>

int				pre(size_t *len, char *arg, va_list *ap)
{
	int		pre;

	pre = 0;
	while (arg[*len] && arg[*len] != '.')
	{
		if (arg[*len] == '*')
			pre = va_arg(*ap, size_t);
		if (arg[*len] <= '9' && arg[*len] >= '1')
		{
			pre = ft_atoi(arg + *len);
			*len += ft_nbrlen(pre) - 1;
		}
		(*len)++;
	}
	return (pre);
}

static void		first_pre(t_fmtid *id, va_list *ap, size_t *len)
{
	int		p;
	char	*tmp;

	p = pre(len, id->full_arg, ap);
	if (p < 0)
	{
		tmp = ft_strjoin("-", id->flag);
		ft_memdel((void **)&(id->flag));
		id->flag = tmp;
		p *= -1;
	}
	id->fp = p;
}

t_fmtid			detect_pre(t_fmtid id, va_list *ap)
{
	size_t	len;
	size_t	last;
	int		p;

	len = 0;
	last = 0;
	if (id.full_arg == NULL)
		return (id);
	first_pre(&id, ap, &len);
	while (id.full_arg[len])
	{
		if (id.full_arg[len] == '.')
			last = len;
		len++;
	}
	last++;
	p = 0;
	id.lp = (id.full_arg[last - 1] == '.') ? pre(&last, id.full_arg, ap) : 0;
	return (id);
}
