/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

char	*ft_null_str(t_info *pfinfo)
{
	char *temp;

	if (pfinfo->prec >= 1 || pfinfo->prec == -1)
	{
		temp = ft_strdup("(null)");
		if (pfinfo->prec > 6)
			temp[6] = '\0';
		else
			temp[(pfinfo->prec == -1) ? 6 : pfinfo->prec] = '\0';
	}
	else
		temp = ft_strdup("");
	return (temp);
}

void	ft_str_conv(t_vector *vector, t_info *pfinfo, va_list ap)
{
	char *ctemp;
	char *str;

	if (pfinfo->length == l)
	{
		ft_wstr_conv(vector, pfinfo, ap);
		return ;
	}
	ctemp = va_arg(ap, char *);
	if (!ctemp)
		str = ft_null_str(pfinfo);
	else
		str = ft_strdup(ctemp);
	ft_prec_handle(pfinfo, &str);
	ft_pad_handle(pfinfo, &str);
	ft_vector_append(vector, str);
	free(str);
}
