//
// Created by Jefferson LE QUELLEC on 10/13/17.
//

#include <sh.h>

/*
*************** PRIVATE ********************************************************
*/

static size_t	get_length(char *str, size_t index, bool rounds)
{
	size_t	length;
	int		s_quote;
	int		d_quote;

	length = 0;
	s_quote = 0;
	d_quote = 0;

	while (str[index])
	{
		if (chk_slash(str, index - 1) == true)
		{
			chk_quotes(str[index], '\"', &s_quote, &d_quote);
			chk_quotes(str[index], '\'', &d_quote, &s_quote);
			if (s_quote == 0 && d_quote == 0 && chk_operaters(str[index]) == rounds)
				return (length);
		}
		index++;
		length++;
	}
	return (length);
}


/*
******************* PUBLIC *****************************************************
*/

void			lexing(t_parsing **new, char *str)
{
	size_t	index;
	size_t	length;
	bool	rounds;
	char	*word;

	if (str)
	{
		index = 0;
		rounds = true;

		while (str[index])
		{
			length = get_length(str, index, rounds);
			rounds = rounds == true ? false : true;
			word = ft_strsub(str, (unsigned int)index, length);
			lstnew(new, word);
			ft_memdel((void **) &word);
			index += length;
		}
	}
}