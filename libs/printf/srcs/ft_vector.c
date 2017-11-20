/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libftprintf.h>

int		ft_vector_init(t_vector *vector, size_t init_cap)
{
	if (!vector || !init_cap)
		return (FAILED);
	vector->len = 0;
	vector->cap = init_cap;
	if ((vector->data = ft_memalloc(sizeof(char) * vector->cap)) == NULL)
		return (FAILED);
	return (SUCCESS);
}

void	ft_vector_append(t_vector *vector, char *newdata)
{
	size_t nd_len;

	nd_len = ft_strlen(newdata);
	if (vector->cap < vector->len + nd_len)
		ft_vector_resize(vector, vector->len + nd_len);
	ft_memcpy(vector->data + vector->len, newdata, nd_len);
	vector->len += nd_len;
}

void	ft_vector_resize(t_vector *vector, size_t min)
{
	size_t	mllc_size;

	if (!(vector->data))
		ft_vector_init(vector, min);
	mllc_size = vector->cap;
	while (mllc_size < min)
		mllc_size *= 2;
	vector->data = (char *)ft_recalloc(vector->data, vector->len, mllc_size);
	vector->cap = mllc_size;
}

void	ft_vector_nappend(t_vector *vector, char *newdata, size_t n)
{
	size_t nd_len;

	nd_len = n;
	if (vector->cap < vector->len + nd_len)
		ft_vector_resize(vector, vector->len + nd_len);
	ft_memcpy(vector->data + vector->len, newdata, nd_len);
	vector->len += nd_len;
}

void	ft_vector_free(t_vector *vector)
{
	if (vector->data && vector->cap > 0)
	{
		free(vector->data);
		vector->data = NULL;
	}
}
