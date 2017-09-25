/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbourson <gbourson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 22:56:07 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/25 17:05:13 by gbourson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int 	ft_size_cmd(t_cmd *cmd)
{
	t_cmd 	*tmp;
	int 	size;

	tmp = NULL;
	tmp = cmd;
	size = 0;
	if(!tmp)
		return (0);
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

char  	*convert_lst_to_string(t_cmd *cmd)
{
	t_cmd 	*tmp;
	int 	i;
	char 	*str;
	int 	count;

	tmp = NULL;
	tmp = cmd;
	i = 0;
	count = ft_size_cmd(cmd);
	if(count)
		str = ft_memalloc((count + 1) * sizeof(char));
	else 
		return (NULL);
	while (tmp)
	{
		str[i] = tmp->c;
		tmp = tmp->next;
		i++;
	}
	str[i + 1] = '\0';
	return (str);
}	

int		shell(void)
{
	t_read *read_std;
	char 	*c;
	t_cmd *cmd;

	add_hash("Alexandre", "@aroulin", 42);
	add_hash("Gregoire", "@gbourson", 42);
	add_hash("Jefferson", "@jle-quel", 42);
	add_hash("Didier", "@dsebban", 42);

	hash_print();

	read_std = read_stdin();
	cmd = first_cmd(read_std->cmd, 1);
	/************GREG PART*************/
	c = convert_lst_to_string(cmd);
	parse_builtins(c);
	/************GREG PART*************/
	var_return(0);
	read_stdin();
	reset_signal();
	return (1);
}
