/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:34:27 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/18 17:26:14 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
		new->content = NULL;
	else
	{
		new->content = (void *)malloc(content_size);
		ft_memcpy(new->content, content, content_size);
	}
	new->content_size = new->content == NULL ? 0 : content_size;
	new->next = (NULL);
	return (new);
}
