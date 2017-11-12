/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:59:51 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/10 18:45:50 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
**			PARSING
*/

# define TOKEN 1
# define OPERATER 2
# define IO_NUMBER 3
# define SLASH 2

/*
**			ERROR
*/

# define SYNTAX_ERR 666

/*
**			TOOLS
*/

# define CURSOR					"\033[6n"
# define OPTION_GREAT			O_CREAT | O_WRONLY | O_TRUNC
/*
**			FLAG EXECUTION
*/

# define FORK						1
# define FOREGROUND					2
# define WRITE_PREVIOUS				4
# define READ						8
# define CLOSE						16
# define DONT_EXECUTE				32
/*
**			TOKEN RECOGNITION
*/

# define PRIO_SEPARATOR				1
# define PRIO_CMD_AND_OR			2
# define PRIO_PIPE					3
# define PRIO_REDIR					4
# define PRIO_COMMAND				5

/*
** COMAND		...
** SEMI_COLON	;
** AMPERSAND	&
** AND_IF		&&
** OR_IF		||
** PIPELINE		|
** LESS			<
** GREAT		>
** DLESS		<<
** DGREAT		>>
** LESS_AND		<&
** GREAT_AND	&>
*/

# define NOTHING					-1
# define VALUE_COMMAND				0
# define VALUE_SEMI_COLON			1
# define VALUE_AMPERSAND			2
# define VALUE_AND_IF				3
# define VALUE_OR_IF				4
# define VALUE_PIPELINE				5
# define VALUE_LESS					6
# define VALUE_GREAT				7
# define VALUE_DLESS				8
# define VALUE_DGREAT				9
# define VALUE_LESS_AND				10
# define VALUE_GREAT_AND			11

/*
**			INITIALIZATION FLAGS
*/

# define RESET_STRUCT			1
# define SAVE_STRUCT			2
# define REC_STRUCT				4

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

# define DEFAULT				1
# define DQUOTE					2
# define QUOTE					4
# define NEXTCMD				8
# define HEREDOC				16
# define PRINT					32

/*
**			INITIALIZATION READ
*/

# define REFRESH				0
# define CTRL_A					1
# define CTRL_B					2
# define CTRL_D					4
# define CTRL_E					5
# define CTRL_F					6
# define TAB_KEY				9
# define CTRL_P					16
# define CTRL_K					11
# define CLEAR_KEY				12
# define CTRL_N					14
# define CTRL_R					18
# define CTRL_UNDO				31
# define DELETE_KEY				127
# define PRINT_KEY				424242

# define META_L					27675
# define META_C					25371
# define META_U					29979
# define META_Y					31003
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
**			USAGE DEFINE
*/

# define H_J					"Usage for jobs :\n"
# define H_E					"Usage for env :\n"
# define H_B					"Usage for hash :\n"
# define H_H					"Usage for history :\n"
# define H_K					"Usage for kill :\n"

# define H_HJ					"-j                      : usage jobs\n"
# define H_HE					"-e                      : usage env\n"
# define H_HB					"-b                      : usage hash\n"
# define H_HH					"-h                      : usage history\n"
# define H_HK					"-k                      : usage kill\n"

# define H_MOVE					"Commands For Moving :\n"
# define H_CA					"C-a                     : Move to the start of\
 he current line. \n"
# define H_CE					"C-e                     : Move to the end of \
he line. \n"
# define H_CF					"C-f                     : Move forward a \
haracter.  \n"
# define H_CB					"C-b                     : Move back a\
 character.  \n"
# define H_MF					"M-f                     : Move forward to the \
end of the next word.\n"
# define H_MB					"M-b                     : Move back to the \
start of this, or the previous, word.\n"
# define H_CL					"C-l                     : Clear the screen \
nd redraw the current line.\n"

# define H_HISTORY				"Commands For Manipulating The History :\n"
# define H_CP					"C-p                     : Move `up' through\
 the history list. \n"
# define H_CN					"C-n                     : Move `down' through \
the history list. \n"
# define H_CR					"C-r                     : Search backward \
starting \
at the current line and moving `up' through the history as necessary.\n"
# define H_CD					"C-d                     : Delete the character\
 under the cursor. If the cursor is at the beginning of the line, there are no \
characters in the line, and the last character typed was not bound to \
delete-char, then return EOF.\n"
# define H_MU					"M-u                     : Uppercase the \
current (or following) word.\n"
# define H_ML					"M-l                     : Lowercase the \
current (or following) word.\n"
# define H_MC					"M-c                     : A FAIRE :Capitalize \
the current (or following) word.\n"

# define H_KILL_AND_YANK		"Killing And Yanking :\n"
# define H_CK					"C-k                     : Kill the text from\
 the current cursor position to the end of the line.\n"
# define H_MD					"M-d                     : Kill from the cursor\
 to the end of the current word, or if between words, to the end of \
the next word. \n"
# define H_MDEL					"M-DEL                   : Kill the word behind\
 the cursor. \n"
# define H_MY					"M-y                     : A FAIRE :Yank the \
top of the kill ring into the buffer at the current cursor position.\n"




# define HASH_R					"-r                      : Reset the hash \
table.\n"
# define HASH_DEFAULT			"otherwise               : Print the hash \
list.\n"
# define HISTORY_L				"-c                      : Clear the history \
list.\n"
# define HISTORY_D				"-d offset               : Delete the history\
entry at \
position offset.\n"
# define HISTORY_R				"-r [pathname]           : Read the history \
file\
 and append its contents to the history list.\n"
# define HISTORY_W				"-w [pathname]           : Write out the \
current\
 history list to the history file.\n"
# define HISTORY_DEFAULT		"otherwise               : Print history list\n"

# define JOBS_P					"-p                      : List only the \
process\
ID of the job’s process group leader.\n"
# define JOBS_R					"-r                      : Display only \
running \
jobs.\n"
# define JOBS_S					"-s                      : Display only stopped\
jobs.\n"
# define JOBS_L					"-l                      : List process IDs in \
addition to the normal information.\n"
# define JOBS_DEFAULT			"otherwise               : Display all jobs.\n"

# define KILL_L					"-l                      : If no operand is \
given, list the signal names; otherwise, write the signal name corresponding to\
 exit_status.\n"
# define KILL_NAME				"-[signal_name]   pid .. : A symbolic signal \
name specifying the signal \
to be sent instead of the default TERM.\n"
# define KILL_NUMBER			"-[signal_number] pid .. : A non-negative \
decimal integer, specifying \
the signal to be sent instead of the default TERM.\n"
# define ENV_DEFAULT			"[name=value ...]        : Add [name=value] to\
 own env temporarily.\n"
# define ENV_U					"-i [name=value ...]     : Add [name=value] \
to empty env temporarily.\n"
# define ENV_I					"-u [name]               : Remove [name] to \
own env temporarily.\n"

/*
**			VARIOUS DEFINE
*/

# define FG						"fg: "
# define EXIT					"exit: "
# define BG						"bg: "
# define KILL					"kill: "
# define ENV					"env: "
# define HISTORY				"history: "

# define INVALID				"invalid argument : "
# define NO_ARGS_U				"option requires an argument -- u"
# define OPTION_NO_FOUND		"option not found : "
# define NO_JOB					"job not found: "
# define NO_CUR_JOB				"no current job :"
# define UNKNOWN				"unknown signal: "
# define NO_ARGS				"not enough arguments : "
# define NO_PROCESS				"no such process: "
# define ILLEGAL				"illegal pid: "
# define EXPECT					"signal name expected :"
# define TOO_MANY_ARGS			"too many arguments :"
# define NUM_REQUIRED			"numeric argument required :"
# define RUN					"Runing"
# define STOP					"Stopped"

# define HISTSIZE				500
# define HELP					"--help"
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
