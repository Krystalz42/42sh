/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 16:17:34 by sbelazou          #+#    #+#             */
/*   Updated: 2017/10/24 15:37:20 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_bdata				*b_data()
{
	static t_bdata	*data = NULL;

	if (data == NULL)
		if (!(data = (t_bdata *)malloc(sizeof(*data))))
			return (NULL);
	return (data);
}
