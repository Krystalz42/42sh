/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 15:21:08 by aroulin           #+#    #+#             */
/*   Updated: 2017/04/18 17:23:04 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include <stdarg.h>
#include <libft.h>
#include <ft_printf.h>

static int		acceptable(char fmt)
{
	if (ft_strchr("E*sSpdDioOuUxXcCbfF%#+- hljz.0123456789", fmt))
		return (1);
	return (0);
}

static int		check_color(char **fmt, t_fmtid *id)
{
	if ((id->dif = if_color(*fmt)) != NULL)
		*fmt += 5;
	else
	{
		*fmt += 1;
		id->dif = "{";
	}
	id->arg = '<';
	id->dif = ft_strdup(id->dif);
	return (1);
}

static char		*check_flag(char *flag, char *full_arg)
{
	int i;
	int len;

	len = 0;
	i = 0;
	flag = NULL;
	while (full_arg[i] && !(ft_strchr("eEsSpdDioOuUxXcCbfF%", full_arg[i])) &&
			acceptable(full_arg[i]))
	{
		if (ft_strchr("*#+- hljz.", full_arg[i]) ||
				(full_arg[i] == '0' && !ft_isdigit(full_arg[i - 1])))
		{
			if (len == 0)
				flag = ft_strnew(1);
			else
				flag = (char *)ft_realloc((void **)(&flag), len + 1);
			flag[len] = full_arg[i];
			len++;
		}
		i++;
	}
	return (clear_flag(flag));
}

static int		full_arg(t_fmtid *id, char **fmt)
{
	int		len;

	len = 0;
	while ((*fmt)[len] && (!ft_strchr("eEsSpdDioOuUxXcCbfF%", (*fmt)[len])) &&
			acceptable((*fmt)[len]))
		len++;
	if ((*fmt)[len])
		len++;
	else
	{
		(*fmt) += len;
		id->arg = '|';
		return (-1);
	}
	id->full_arg = ft_strsub(*fmt, 0, len);
	if (len != 0 && !ft_strchr("sSpdDioOuUxXcCbfF%", id->full_arg[len - 1]))
		id->arg = '/';
	else
		id->arg = id->full_arg[len - 1];
	id->sign = id->full_arg[len - 1];
	(*fmt) += len;
	return (1);
}

t_fmtid			format_identifier(char **fmt)
{
	int		i;
	t_fmtid id;

	id.dif = NULL;
	id.full_arg = NULL;
	id.flag = NULL;
	id.arg = 0;
	if (**fmt == '{' && check_color(fmt, &id))
		return (id);
	i = 0;
	(*fmt)++;
	if (full_arg(&id, fmt) != -1)
		id.flag = check_flag(id.flag, id.full_arg);
	return (id);
}
