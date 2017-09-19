/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:55:50 by aroulin           #+#    #+#             */
/*   Updated: 2017/04/18 17:17:18 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <get_next_line.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char	*my_realloc(char *str, int size)
{
    char	*new;
    int		i;

    if ((new = ft_strnew(size)) == NULL)
        return (NULL);
    i = 0;
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = 0;
    free(str);
    return (new);
}

char	*destroy_buffer(char *d, int len)
{
    char	*tmp;
    int		lend;

    lend = ft_strlen(d);
    tmp = NULL;
    if (*d && lend >= len)
        if ((tmp = ft_strsub(d, len, lend - len)) == NULL)
            return (NULL);
    return (tmp);
}

int		struct_init(t_fd *tab, int i, int *len, int *r)
{
    char	*buff;

    buff = ft_strnew(BUFF_SIZE);
    *len = ft_strlen(tab->d[i]);
    while ((*r = 0) == 0 && tab->count[i] == 0)
    {
        if ((*r = read(tab->fd[i], buff, BUFF_SIZE)) == -1)
            return (-1);
        tab->d[i] = *r > 0 ? my_realloc(tab->d[i], *len + *r) : tab->d[i];
        r = r > 0 && ft_memcpy(tab->d[i] + *len, buff, *r) ? r : r;
        *len += *r;
        tab->count[i] = ft_chrchar(buff, '\n');
        if (*r != BUFF_SIZE)
            break ;
    }
    free(buff);
    if ((ft_strlen(tab->d[i]) == 0) &&
        ((tab->bol[i] == 0 && *r == 0) || (*r == 0 && tab->bol[i] == 0)))
        return (0);
    tab->bol[i] = 1;
    if ((ft_strlen(tab->d[i]) == 0) && ((*r == 0 && tab->count[i] == 0)
                                        || (tab->count[i] == 0 && *r != BUFF_SIZE)))
        tab->bol[i] = -1;
    tab->count[i]--;
    return (1);
}

int		read_it(t_fd *tab, int i, char **line)
{
    int		len;

    len = 0;
    if (tab->bol[i] != -1)
        while (tab->d[i][len] != '\n' && tab->d[i][len] != '\0')
            len++;
    if (tab->bol[i] != -1)
        if ((*line = ft_strsub(tab->d[i], 0, len)) == NULL)
            return (-1);
    if ((tab->d[i] = destroy_buffer(tab->d[i], len + 1)) == NULL)
        tab->bol[i] = -1;
    return (1);
}

int		my_gnl(int fd, char **line)
{
    static t_fd	tab;
    int				len;
    int				r;
    int				err;

    if (line == NULL || fd < 0 || BUFF_SIZE == 0)
        return (-1);
    tab.i = -1;
    while (++tab.i < 49 && tab.first == 0)
        tab.fd[tab.i] = -1;
    tab.first = 1;
    tab.i = 0;
    while (tab.i < 49 && tab.fd[tab.i] != -1 && tab.fd[tab.i] != fd)
        tab.i++;
    tab.fd[tab.i] = fd;
    if (tab.bol[tab.i] == -1)
        return (0);
    tab.d[tab.i] = tab.bol[tab.i] == 0 ? ft_strnew(1) : tab.d[tab.i];
    if ((err = struct_init(&tab, tab.i, &len, &r)) != 1)
        return (err);
    if (len == 0 && r == 0)
        return (0);
    if ((err = read_it(&tab, tab.i, line)) != 1)
        free(tab.d[tab.i]);
    return (err);
}

