/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 15:26:51 by jgraille          #+#    #+#             */
/*   Updated: 2016/11/18 18:53:47 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL)
	{
		if (*alst != NULL)
		{
			ft_lstdel(&((*alst)->next), del);
			ft_lstdelone(alst, del);
		}
		free(*alst);
		alst = NULL;
	}
}
