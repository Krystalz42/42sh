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

# define RESET_STRUCT			0
# define SAVE_STRUCT			1
# define REC_STRUCT				2

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

/*
**			INITIALIZATION READ
*/

# define CTRL_A					1
# define CTRL_B					2
# define CTRL_D					4
# define CTRL_E					5
# define CTRL_F					6
# define TAB_KEY				9
# define CTRL_K					11
# define CLEAR_KEY				12
# define REFRESH				14
# define CTRL_R					18
# define CTRL_UNDO				31
# define DELETE_KEY				127
# define PRINT_KEY				424242

# define META_L					27675
# define META_U					29979
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

# define DEL_KEY				2117294875

# define SHIFT_UP_KEY			71683997260571
# define SHIFT_DOWN_KEY			72783508888347
# define SHIFT_RIGHT_KEY		73883020516123
# define SHIFT_LEFT_KEY			74982532143899

/*
**			VARIOUS DEFINE
*/

# define FG						"fg: "
# define BG						"bg: "
# define KILL					"kill: "
# define ENV					"env: "
# define INVALID				"Invalid argument : "
# define NO_ARGS_U				"option requires an argument -- u"
# define NO_JOB					"job not found: "
# define NO_CUR_JOB				"no current job :"
# define UNKNOWN				"unknown signal: "
# define NO_ARGS				"not enough arguments: "
# define NO_PROCESS				"no such process: "
# define ILLEGAL				"illegal pid: "
# define EXPECT					"signal name expected"


# define HISTSIZE				500

# define MAX_CHILD				8096
# define PATH_HISTORY			"/.42sh_history"
# define PATH_HASH				"/.42sh_hash"
# define PATH_ERR				"/dev/null"

# define MV_LEFT				"le"
# define MV_BOT					"do"
# define MV_TOP					"up"
# define SAVE 					"sc"
# define RESTORE				"rc"
# define CURSOR_INVIS			"vi"
# define CURSOR_BACK			"ve"
# define CLEAR_FROM_CUR			"cd"
# define BACK_N					"cr"
# define MV_RIGHT				"nd"

# define CLEAR					"cl"

#endif
