//
// Created by Alexandre ROULIN on 9/19/17.
//

#include <sh.h>

char     *get_str_from_hash(void)
{
    char *home;

    if (!(home = my_getenv("HOME")))
        return (NULL);
    return (ft_strjoin(home, PATH_HASH));
}
