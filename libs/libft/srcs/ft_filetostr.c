/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filetostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 00:00:21 by aroulin           #+#    #+#             */
/*   Updated: 2016/01/01 00:00:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char		*ft_filetostr(char *filepath)
{
	char	buff[1000];
	size_t	len;
	size_t	ret;
	int		ref;
	char	*str;

	ref = open(filepath, O_RDONLY);
	if (ref == -1)
		return (NULL);
	len = 0;
	ret = 1;
	while (ret != 0)
	{
		ret = read(ref, buff, 1000);
		len += ret;
	}
	close(ref);
	str = (char *)malloc(len + 1);
	ref = open(filepath, O_RDONLY);
	while (read(ref, buff, 1000))
		ft_strlcat(str, buff, len);
	close(ref);
	return (str);
}
