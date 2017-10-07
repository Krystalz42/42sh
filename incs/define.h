/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:59:51 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/24 17:13:15 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
**			INITIALIZATION FLAGS
*/

# define ENV_NULL				1
# define ENV_INIT				2
# define ENV_REC				4
# define ENV_CPY				8

# define OLD_TERM				1
# define OUR_TERM				2
# define SAVE_OLD				4
# define SAVE_OUR				8

# define SET_OLD_TERM			1
# define SET_OUR_TERM			2

# define HEREDOC				1
# define DQUOTE					2
# define QUOTE					4
# define NEXTCMD				8
# define DEFAULT				16
# define PRINT					32

# define NEW_CHILD_FG			1
# define NEW_CHILD_BG			2
# define UPDATE_CHILD			4
# define SIGNAL_RECEPTION		8
# define SIGNAL_SIGCHLD			16
# define INITIALIZE_TO_ZERO		32
# define FOREGROUND				64
# define BACKGROUND				128


/*
**			INITIALIZATION READ
*/

# define DELETE_KEY				127
# define TAB_KEY				9
# define ENTER_KEY				10
# define CLEAR_KEY				12

# define INTERRUPT_KEY			2
# define CTRL_F					6
# define CTRL_D					4
# define CTRL_A					1
# define CTRL_E					5
# define CTRL_K					11
# define CTRL_R					18
# define CTRL_V					22
# define CTRL_W 				23
# define CTRL_UNDO				31
# define PRINT_KEY				424242

# define META_Y					42434
# define META_F					26139
# define META_D					25627
# define META_DEL				32539
# define META_B					25115

# define ARROW_LEFT				4479771
# define ARROW_DOWN				4348699
# define ARROW_UP				4283163
# define ARROW_RIGHT			4414235
# define END_KEY				4610843
# define HOME_KEY				4741915

# define PAGE_UP				2117425947
# define PAGE_DOWN				2117491483

# define DEL_KEY				2117294875

# define SHIFT_UP_KEY			71683997260571
# define SHIFT_DOWN_KEY			72783508888347
# define SHIFT_RIGHT_KEY		73883020516123
# define SHIFT_LEFT_KEY			74982532143899

# define CTRL_SHIFT_RIGHT_KEY	73900200385307
# define CTRL_SHIFT_LEFT_KEY	74999712013083

/*
**			VARIOUS DEFINE
*/

# define MAX_CHILD				8096

# define HISTSIZE				500
# define PATH_HISTORY			"/.42sh_history"
# define PATH_HASH				"/.42sh_hash"
# define PATH_GIT				"/tmp/.git_info"
# define PATH_PWD				"/tmp/.pwd_info"
# define PATH_ERR				"/dev/null"

# define MV_RIGHT				tputs(tgetstr("nd", 0), 0, &my_put)
# define MV_LEFT				tputs(tgetstr("le", 0), 0, &my_put)
# define MV_BOT					tputs(tgetstr("do", 0), 0, &my_put)
# define MV_TOP					tputs(tgetstr("up", 0), 0, &my_put)
# define SAVE 					tputs(tgetstr("sc", 0), 0, &my_put)
# define RESTORE				tputs(tgetstr("rc", 0), 0, &my_put)
# define CURSOR_INVIS			tputs(tgetstr("vi", 0), 0, &my_put)
# define CURSOR_BACK			tputs(tgetstr("ve", 0), 0, &my_put)
# define CLEAR_FROM_CUR			tputs(tgetstr("cd", 0), 0, &my_put)
# define BACK_N					tputs(tgetstr("cr", 0), 0, &my_put)
# define CLEAR					tputs(tgetstr("cl", 0), 0, &my_put)

#endif
