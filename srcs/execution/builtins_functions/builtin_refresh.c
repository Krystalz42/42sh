/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_varenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 15:14:26 by sbelazou          #+#    #+#             */
/*   Updated: 2017/10/24 15:38:30 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

char		*add_envar(char *var, char *value)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * (ft_strlen(var) + ft_strlen(value)) + 2)))
		return (NULL);
	str = ft_strcpy(str, var);
	str = ft_strcat(str, value);
	return (str);
}

char		**refresh_varenv(char **env)
{
	int		pos;
	char	*var;
	char	buff[UCHAR_MAX];

	pos = 0;
	if (getcwd(buff, UCHAR_MAX) == NULL)
		return (env);
	if (!ft_strcmp(b_data()->pwd, buff))
		return (env);
	if (b_data()->oldpwd != NULL)
		free(b_data()->oldpwd);
	b_data()->oldpwd = ft_strdup(b_data()->pwd);
	free(b_data()->pwd);
	b_data()->pwd = ft_strdup(buff);
	pos = search_in_tab(env, "PWD=");
	free(env[pos]);
	env[pos] = ft_strdup(var = add_envar("PWD=", b_data()->pwd));
	free(var);
	pos = search_in_tab(env, "OLDPWD=");
	free(env[pos]);
	env[pos] = ft_strdup(var = add_envar("OLDPWD=", b_data()->oldpwd));
	free(var);
	return (env);
}
