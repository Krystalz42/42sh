#include <sh.h>

unsigned int		hash_value(char *str)
{
	int 		i= -1;
	unsigned int nb;

	nb = 0;
	if (str[0] == '.')
		return (0);
	while (str[++i])
	{
		nb += str[i];
		nb += (nb << 10);
		nb ^= (nb >> 6);
	}
	nb += (nb << 3);
	nb ^= (nb >> 11);
	nb += (nb << 15);
	nb = ((nb) % LEN_HASH);
	return (nb);
}
