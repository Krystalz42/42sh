/*                                                        :::      ::::::::   */
/*   read_stdin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2027/08/09 22:42:45 by aroulin           #+#    #+#             */
/*   Updated: 2027/08/20 24:57:27 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

t_cmp		compare_key[] = {
	(t_cmp){DELETE_KEY, keyDel},
	(t_cmp){EOF_KEY, keyEof},
	(t_cmp){TAB_KEY, keyTab},
	(t_cmp){ENTER_KEY, keyEnter},
	(t_cmp){INTERRUPT_KEY, keyInterrupt},
	(t_cmp){CLEAR_KEY, keyClear},
	(t_cmp){HOME_KEY, keyHome},
	(t_cmp){END_KEY, keyEnd},
	(t_cmp){DEL_KEY, keyDeleteHere},
	(t_cmp){PAGE_UP, keyDel},
	(t_cmp){PAGE_DOWN, keyDel},
	(t_cmp){ARROW_DOWN, keyArrowDown},
	(t_cmp){ARROW_LEFT, keyArrowLeft},
	(t_cmp){ARROW_RIGHT, keyArrowRight},
	(t_cmp){ARROW_UP, keyArrowUp},
	(t_cmp){HOME_KEY, keyHome},
	(t_cmp){SHIFT_UP_KEY, keyShiftUp},
	(t_cmp){SHIFT_DOWN_KEY, keyShiftDown},
	(t_cmp){SHIFT_RIGHT_KEY, keyShiftRight},
	(t_cmp){SHIFT_LEFT_KEY, keyShiftLeft},
	(t_cmp){NULL, NULL}
};

int				init_buff(char *buff, int *i, t_read **readStd)
{
	ft_bzero(buff, LEN_BUFFER);
	*i = -1;
	((*readStd)->completion) && (--(*readStd)->completion);
	(!(*readStd)->completion) && printStruct((*readStd)) && memdelCompletion(&((*readStd)->comp));
	return (1);
}

t_read					*initStructForRead(void)
{
	t_read		*readStd;

	if (!(readStd = (t_read *)ft_memalloc(sizeof(t_read))))
		return (NULL);
	if (!(readStd->cmd = createElement('\0')))
		return (NULL);
	gblSaveRead(readStd->cmd);
	return (readStd);
}

t_read			*readStdin(void)
{
	char		buff[LEN_BUFFER];
	t_read		*readStd;
	int			c;
	int			i;
	
	if (!(readStd = initStructForRead()))
		return (NULL);
	readStd->cur.co = prompt(DEFAULT, "&> ");
	init_buff(buff, &i, &readStd);
	setTermios(SET_OUR_TERM);
	while ((c = -1) && read(STDIN_FILENO, &(buff[++i]), sizeof(char)))
	{
		if (PRINT_KEY(buff[0]))
			keyPrint(&readStd, buff[0]) && init_buff(buff, &i, &readStd);
		while (compare_key[++c].key)
			if (!ft_strcmp(compare_key[c].key, buff))
				compare_key[c].function(&readStd) && init_buff(buff, &i, &readStd);
		if ((readStd)->finish)
			break ; 
	}
	setTermios(SET_OLD_TERM);
	finishReadStd(&readStd);
	return (readStd);
}
