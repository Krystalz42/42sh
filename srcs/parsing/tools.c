//
// Created by Jefferson LE QUELLEC on 10/13/17.
//

#include <sh.h>

/*
*************** PUBLIC *********************************************************
*/

bool			chk_operaters(char c)
{
	size_t				index;
	static const char 	operater[6] = "&|<>;";

	index = 0;
	while (operater[index])
	{
		if (c == operater[index])
			return (true);
		index++;
	}
	return (false);
}

bool			chk_slash(const char *str, size_t index)
{
	size_t	occurence;

	occurence = 0;
	while (str[index])
	{
		if (str[index] == '\\')
			occurence++;
		else
			break ;
		index--;
	}
	return (occurence % 2 == 0 ? true : false);
}

void			chk_quotes(char c, char quote, const int *flag, int *value)
{
	if (*flag == 0)
	{
		if (c == quote)
			*value = *value == 0 ? 1 : 0;
	}
}

