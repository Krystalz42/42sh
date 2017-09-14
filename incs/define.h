/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 23:25:58 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/30 17:40:53 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
**			INITIALIZATION FLAGS
*/

# define LEN_BUFFER         7

# define ENV_NULL	        1
# define ENV_INIT	        2
# define ENV_REC	        4

# define OLD_TERM	        1
# define OUR_TERM	        2
# define SAVE_OLD	        4
# define SAVE_OUR	        8

# define SET_OLD_TERM	    1
# define SET_OUR_TERM	    2

# define HEREDOC		    1
# define DQUOTE			    2
# define QUOTE			    4
# define NEXTCMD		    8
# define DEFAULT		    16
# define PRINT			    32

# define LEN_HASH UINT_MAX - 1

/*
**			INITIALIZATION READ
*/

# define DELETE_KEY		    	"\x7f\x0\x0\x0\x0\x0"
# define EOF_KEY			    "\x4\x0\x0\x0\x0\x0"
# define TAB_KEY		    	"\x9\x0\x0\x0\x0\x0"
# define ENTER_KEY		    	"\xA\x0\x0\x0\x0\x0"
# define CLEAR_KEY		    	"\xc\x0\x0\x0\x0\x0"
# define INTERRUPT_KEY	    	"\x2\x0\x0\x0\x0\x0"
# define CTRL_R                 "\x12\x0\x0\x0\x0\x0"

# define ARROW_LEFT		    	"\x1b\x5b\x44\x0\x0\x0"
# define ARROW_DOWN		    	"\x1b\x5b\x42\x0\x0\x0"
# define ARROW_UP		    	"\x1b\x5b\x41\x0\x0\x0"
# define ARROW_RIGHT		    "\x1b\x5b\x43\x0\x0\x0"
# define END_KEY		    	"\x1b\x5b\x46\x0\x0\x0"
# define HOME_KEY		    	"\x1b\x5b\x48\x0\x0\x0"

# define PAGE_UP		    	"\x1b\x5b\x36\x7e\x0\x0"
# define PAGE_DOWN		    	"\x1b\x5b\x35\x7e\x0\x0"

# define DEL_KEY		    	"\x1b\x5b\x33\x7e\x0\x0"

# define SHIFT_UP_KEY	    	"\x1b\x5b\x31\x3b\x32\x41"
# define SHIFT_DOWN_KEY	    	"\x1b\x5b\x31\x3b\x32\x42"
# define SHIFT_RIGHT_KEY	    "\x1b\x5b\x31\x3b\x32\x43"
# define SHIFT_LEFT_KEY		    "\x1b\x5b\x31\x3b\x32\x44"

# define CTRL_SHIFT_RIGHT_KEY   "\x1b\x5b\x31\x3b\x36\x43"
# define CTRL_SHIFT_LEFT_KEY   "\x1b\x5b\x31\x3b\x32\x44"
# define CTRL_SHIFT_UP_KEY	    "\x1b\x5b\x31\x3b\x32\x41"
# define CTRL_SHIFT_DOWN_KEY	"\x1b\x5b\x31\x3b\x32\x42"

# define PRINT_KEY(x) (x >= '\x20' && x <= '\x7E')

# define MV_RIGHT			tputs(tgetstr("nd", 0), 0, &my_put)
# define MV_LEFT			tputs(tgetstr("le", 0), 0, &my_put)
# define MV_BOT				tputs(tgetstr("do", 0), 0, &my_put)
# define MV_TOP				tputs(tgetstr("up", 0), 0, &my_put)
# define SAVE 				tputs(tgetstr("sc", 0), 0, &my_put)
# define RESTORE			tputs(tgetstr("rc", 0), 0, &my_put)
# define CURSOR_INVIS		tputs(tgetstr("vi", 0), 0, &my_put)
# define CURSOR_BACK		tputs(tgetstr("ve", 0), 0, &my_put)
# define CLEAR_FROM_CUR		tputs(tgetstr("cd", 0), 0, &my_put)
# define BACK_N				tputs(tgetstr("cr", 0), 0, &my_put)
# define CLEAR				tputs(tgetstr("cl", 0), 0, &my_put)

#endif
