//
// Created by Alexandre ROULIN on 10/26/17.
//

#include <libft.h>

int		ft_strisalpha(char *string)
{
	size_t		index;

	if (!string || (*string) == '\0')
		return (0);
	index = 0;
	while (string[index])
	{
		if (ft_isalpha(string[index]) == 0)
			return (0);
		index++;
	}
	return (1);
}