/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 16:07:04 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/18 19:06:54 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *list, t_list *(*f)(t_list *elem))
{
	t_list *cpy;

	cpy = NULL;
	if (list != NULL)
	{
		cpy = f(ft_lstnew(list->content, list->content_size));
		if (list->next != NULL)
			cpy->next = ft_lstmap(list->next, f);
	}
	return (cpy);
}
