//
// Created by Alexandre ROULIN on 10/15/17.
//

int				ft_iscrlf(char c)
{
	if (c == 10 || c == 13)
		return (1);
	return (0);
}