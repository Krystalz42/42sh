/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 02:02:59 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/11 06:40:37 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmp2		compare_special_key1[] = {
	(t_cmp2){ARROW_DOWN, arrow_down},
	(t_cmp2){ARROW_LEFT, arrow_left},
	(t_cmp2){ARROW_RIGHT, arrow_right},
	(t_cmp2){ARROW_UP, arrow_up},
	(t_cmp2){END_KEY, end_key},
	(t_cmp2){HOME_KEY, home_key},
	(t_cmp2){NULL, NULL}
};

t_cmp2		compare_special_key2[] = {
	(t_cmp2){SHIFT_UP_KEY, shift_up_key},
	(t_cmp2){SHIFT_DOWN_KEY, shift_down_key},
	(t_cmp2){SHIFT_RIGHT_KEY, shift_right_key},
	(t_cmp2){SHIFT_LEFT_KEY, shift_left_key},
	(t_cmp2){NULL, NULL}
};


int			special_key(t_read **read_std)
{
	int		i;
	char	buff;
	char	buff2[2];
	char	buff3[3];

	i = -1;
	read(STDIN_FILENO, &buff2, sizeof(char) * 2);
	while (compare_special_key1[++i].key)
		if (!ft_strncmp(compare_special_key1[i].key, buff2, 2))
			return (compare_special_key1[i].function(read_std));
	read(STDIN_FILENO, &buff, sizeof(char));
	if (DEL_KEY == buff)
		return (del_key(read_std));
	read(STDIN_FILENO, &buff3, sizeof(char) * 3);
	i = -1;
	while (compare_special_key2[++i].key)
		if (!ft_strncmp(compare_special_key2[i].key, buff3, 2))
			return (compare_special_key2[i].function(read_std));
	return (1);
}
