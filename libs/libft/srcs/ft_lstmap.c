/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
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
