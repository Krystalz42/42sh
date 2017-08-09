/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:49:46 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/18 16:16:13 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstcpy(t_list *list)
{
	t_list *cpy;

	if (list != NULL)
	{
		cpy = ft_lstnew(list->content, list->content_size);
		cpy->next = ft_lstcpy(list->next);
		return (cpy);
	}
	else
		return (NULL);
}
