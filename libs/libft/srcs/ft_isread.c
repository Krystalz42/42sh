//
// Created by Alexandre ROULIN on 10/30/17.
//

#include <libft.h>

int			ft_isread(int c)
{
	if (ft_iscrlf(c) || ft_isprint(c))
		return (1);
	return (0);
}
