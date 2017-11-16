//
// Created by Alexandre ROULIN on 11/16/17.
//

int		potential_option(char *potential, int c)
{
	int						index;

	index = 0;
	while (potential[index])
	{
		if (potential[index] == c)
			return (1);
		index++;
	}
	return (0);
}