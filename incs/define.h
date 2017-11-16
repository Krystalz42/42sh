/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:59:51 by aroulin           #+#    #+#             */
/*   Updated: 2017/11/16 16:23:34 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <sh.h>
# include "enum.h"

/*
**			LEXING
*/

# define SINGLE_QUOTE 2
# define DOUBLE_QUOTE 4
# define DQ 4 // Merci a la norme
# define BACKSLASH 8

# define TOKEN 1
# define OPERATER 2

# define SYNTAX_ERR 666

/*
**			TOOLS
*/

# define CURSOR					"\033[6n"
# define OPTION_GREAT			O_CREAT | O_WRONLY | O_TRUNC
# define OPTION_DGREAT			O_CREAT | O_WRONLY | O_APPEND
# define PATH_ERROR				"/dev/null"

/*
**			FLAG EXECUTION
*/

# define FORK						1
# define FOREGROUND					2
# define DONT_EXECUTE				32
# define FORCE_FORK					64

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

/*
**			INITIALIZATION FLAGS
*/

# define MORE					-1
# define KEEP					-2

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
**			USAGE DEFINE
*/

# define H_J					"Usage for jobs :\n"
# define H_E					"Usage for env :\n"
# define H_B					"Usage for hash :\n"
# define H_H					"Usage for history :\n"
# define H_K					"Usage for kill :\n"
# define H_S					"Usage for setenv :\n"
# define H_U					"Usage for unsetenv :\n"
# define H_F					"Usage for foreground :\n"
# define H_G					"Usage for background :\n"
# define H_C					"Usage for cd :\n"

# define H_HJ					"-j                      : usage jobs\n"
# define H_HE					"-e                      : usage env\n"
# define H_HB					"-b                      : usage hash\n"
# define H_HH					"-h                      : usage history\n"
# define H_HK					"-k                      : usage kill\n"
# define H_HS					"-s                      : usage setenv\n"
# define H_HU					"-u                      : usage unsetenv\n"
# define H_HF					"-f                      : usage foreground\n"
# define H_HG					"-g                      : usage background\n"
# define H_HC					"-c                      : usage cd\n"

# define H_MOVE					"Commands For Moving :\n"
# define H_CA					"C-a                     : Move to the start of the current line. \n"
# define H_CE					"C-e                     : Move to the end of \
the line. \n"
# define H_CF					"C-f                     : Move forward a \
character.  \n"
# define H_CB					"C-b                     : Move back a\
 character.  \n"
# define H_MF					"M-f                     : Move forward to the \
end of the next word.\n"
# define H_MB					"M-b                     : Move back to the \
start of this, or the previous, word.\n"
# define H_CL					"C-l                     : Clear the screen \
and redraw the current line.\n"

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
# define H_MC					"M-c                     : Capitalize \
the current (or following) word.\n"
# define H_C_					"C-_                     : Undo the last action\
\n."

# define H_KILL_AND_YANK		"Killing And Yanking :\n"
# define H_CK					"C-k                     : Kill the text from\
 the current cursor position to the end of the line.\n"
# define H_MD					"M-d                     : Kill from the cursor\
 to the end of the current word, or if between words, to the end of \
the next word. \n"
# define H_MDEL					"M-DEL                   : Kill the word behind\
 the cursor. \n"
# define H_MY					"M-y                     : Yank the \
top of the kill ring into the buffer at the current cursor position.\n"

# define HASH_R					"-r                      : Reset the hash \
table.\n"
# define HASH_DEFAULT			"otherwise               : Print the hash \
list.\n"
# define HISTORY_L				"-c                      : Clear the history \
list.\n"
# define HISTORY_D				"-d offset               : Delete the history \
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
# define UNSET					"[name]                  : Unset the variable \
in environement.\n"
# define SET					"[name=value]            : Set the variable \
in environement.\n"

# define FG_DEFAULT				"otherwise               : Put the most large\
 jobs in foreground.\n"
# define FG_JOBSSPEC			"%[number ..]            : Put the specified\
jobs in foreground.\n"
# define BG_JOBSSPEC			"%[number ..]            : Put the specified\
jobs in background.\n"
# define BG_DEFAULT				"otherwise               : Put the most large\
 jobs in background.\n"

# define CD_DEFAULT				"[path]					 : Change the current \
directory.\n"

/*
**			VARIOUS DEFINE
*/

# define FG						"fg: "
# define JOBS					"jobs: "
# define EXIT					"exit: "
# define BG						"bg: "
# define KILL					"kill: "
# define ENV					"env: "
# define HISTORY				"history: "
# define S42H					"42sh: "
# define UNSETENV				"unsetenv : "
# define SETENV					"setenv : "
# define BECHO					"echo : "
# define UCD					"cd : "

# define LIMIT					"limit process at 1024"
# define BAD_FD					" Bad file descriptor"
# define NEED_VALUE				"variable need a name : "
# define INVALID				"invalid argument : "
# define NO_ARGS_U				"option requires an argument -- u"
# define VAR_NO_SET				"variable not set : "
# define WRONG_FORMAT			"variable have wrong format : "
# define BAD_OPTION				"option not found : "
# define NO_JOB					"job not found: "
# define NO_CUR_JOB				"no current job :"
# define UNKNOWN				"unknown signal: "
# define NO_ARGS				"not enough arguments : "
# define NO_PROCESS				"no such process: "
# define ILLEGAL				"illegal pid: "
# define EXPECT					"signal name expected :"
# define TOO_MANY_ARGS			"too many arguments :"
# define NUM_REQUIRED			"numeric argument required :"
# define RUN					"Running"
# define STOP					"Stopped"
# define CONTINUED				"Continued"
# define NO_DIRECTORY			"no such file or directory: "
# define NO_RIGHT				"permission denied: "
# define IS_NOTDIR				"not a directory: "
# define IS_DIR					"is a directory: "
# define NO_ARG					"not argument"

# define HISTSIZE				8096
# define HELP					"--help"
# define MAX_CHILD				1024
# define PATH_HISTORY			"/.42sh_history"
# define PATH_HASH				"/.42sh_hash"

# define OPTION_N				2

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
