/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:45:51 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/19 01:11:28 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

static char			*my_getcwd(void)
{
	char			str[PATH_MAX];
	size_t			len;

	if (getcwd(str, PATH_MAX))
	{
		if (!ft_strcmp(str, "/"))
			return (ft_strdup(str));
		len = ft_strlen(str) - 1;
		while (str[len] && str[len] != '/')
			len--;
		return (ft_strdup(str + (len + 1)));
	}
	return (NULL);
}

static char			*my_color(void)
{
	static int		color = 255;
	static bool		dir = false;

	dir = (color == 237) ? true : dir;
	dir = (color == 255) ? false : dir;
	color = (dir) ? color + 1 : color - 1;
	return (ft_itoa(color));
}

void				init_prompt(void)
{
	static char		*prompt;
	char			*path;
	char			*color;

	path = my_getcwd();
	color = my_color();
	ft_memdel((void **)&prompt);
	prompt = (char *)ft_memalloc(sizeof(char) * \
		(27 + ft_strlen(path)));
	ft_memcpy(prompt + ft_strlen(prompt), "\e[38;5;", 10);
	ft_strcpy(prompt + ft_strlen(prompt), color);
	ft_strcpy(prompt + ft_strlen(prompt), "m");
	ft_strcpy(prompt + ft_strlen(prompt), path);
	ft_strcpy(prompt + ft_strlen(prompt), var_return(-1) ? RED : GRN);
	ft_strcpy(prompt + ft_strlen(prompt), var_return(-1) ? " ✗ " : " √ ");
	ft_strcpy(prompt + ft_strlen(prompt), "\x1B[0m");
	my_prompt(prompt);
	get_len_prompt((int)(ft_strlen(path) + 3));
	free((void *)path);
	free((void *)color);
}
