/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_comp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 04:48:03 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/31 16:42:42 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>
int			managementWildcard(char *data, char *comp);


int			management_wildcard2(char *data, char *comp)
{
	int		neg;
	int		i;
	int		dash;
	char 	match[127];

	dash = 0;
	i = -1;
	ft_bzero(match, 127);
	neg = ((*comp) == '!') && (comp++)? 1 : 0;
	while ((*comp) != ']')
	{
		match[++i] = (*comp);
		dash = ((*comp) == '-') ? i : dash;
		(comp)++;
	}
	if (dash)
		if (neg)
			return (!((*data) >= match[dash - 1] && (*data) <= match[dash + 1])
					? managementWildcard(data + 1, comp + 1) : 0);
		else
			return (((*data) >= match[dash - 1] && (*data) <= match[dash + 1])
					? managementWildcard(data + 1, comp + 1) : 0);
	else
	{
		i = -1;
		while (match[++i])
			if ((neg && *data != match[i]) || (!neg && *data == match[i]))
				return (managementWildcard(data + 1, comp + 1));
	}
	return (0);
}

int			managementWildcard(char *data, char *comp)
{
	if (*data != '\0' && *comp == '[')
		return (management_wildcard2(data, comp + 1));
	if (*data != '\0' && *comp == '?')
		return (managementWildcard(data + 1, comp + 1));
	if (*data != '\0' && *comp == '*')
		return (managementWildcard(data + 1, comp) + managementWildcard(data, comp + 1));
	if (*data == '\0' && *comp == '*')
		return (managementWildcard(data, comp + 1));
	if (*data && *comp && *data == *comp)
		return (managementWildcard(data + 1, comp + 1));
	if (*data == '\0' && *comp == '\0')
		return (1);
	return (0);
}

void		create_comp(t_read **read_std, t_path f)
{
	DIR					*dir;
	struct dirent		*repo = 0;
	int					index;

	index = 0;
	if ((dir = opendir((!f.path ? "." : f.path))))
	{
		while ((repo = readdir(dir)))
			if ((!f.to_comp && repo->d_name[0] != '.') || (f.to_comp && (managementWildcard(repo->d_name, f.to_comp) || !ft_strncmp(f.to_comp, repo->d_name, ft_strlen(f.to_comp) - 1))))
			{
				init_files(&((*read_std)->comp->tab_->file), repo->d_name,
						repo->d_type, index++);
			}
		closedir(dir);
	}
	(*read_std)->comp->tab_->element = index;
}
