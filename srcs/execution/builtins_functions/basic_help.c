/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <jle-quel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 16:30:27 by jle-quel          #+#    #+#             */
/*   Updated: 2017/11/18 17:37:11 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

int			help_move(void)
{
	ft_putstr("Commands For Moving :\n");
	ft_putstr("C-a                     \
: Move to the start of the current line.\n");
	ft_putstr("C-e                     \
: Move to the end of the line. \n");
	ft_putstr("C-f                     \
: Move forward a character.\n");
	ft_putstr("C-b                     \
: Move back a character.\n");
	ft_putstr("M-f                     \
: Move forward to the end of the next word.\n");
	ft_putstr("M-b                     \
: Move back to the start of this, or the previous, word.\n");
	ft_putstr("C-l                     \
: Clear the screen and redraw the current line.\n");
	return (1);
}

int			help_history(void)
{
	ft_putstr("Commands For Manipulating The History :\n");
	ft_putstr("C-p                     \
: Move `up' through the history list.\n");
	ft_putstr("C-n                     \
: Move `down' through the history list.\n");
	ft_putstr("C-r                     \
: Search backward starting at the current line and moving `up' through \
the history as necessary.\n");
	ft_putstr("C-d                     \
: Delete the character under the cursor. If the cursor is at the \
beginning of the line, there are no characters in the line, and \
the last character typed was not bound to delete-char, then return EOF.\n");
	ft_putstr("M-u                     \
: Uppercase the	current (or following) word.\n");
	ft_putstr("M-l                     \
: Lowercase the	current (or following) word.\n");
	ft_putstr("M-c                     \
: Capitalize the current (or following) word.\n");
	return (1);
}

int			help_kill_and_yank(void)
{
	ft_putstr("Killing And Yanking :\n");
	ft_putstr("C-k                     \
: Kill the text from the current cursor position to the end \
of the line.\n");
	ft_putstr("M-d                     \
: Kill from the cursor to the end of the current word, or if \
between words, to the end of the next word. \n");
	ft_putstr("M-DEL                   \
: Kill the word behind the cursor. \n");
	ft_putstr("M-y                     \
: Yank the top of the kill ring into the buffer at the current \
cursor position.\n");
	ft_putstr("C-_                     : Undo the last action\n.");
	return (1);
}
