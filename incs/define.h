/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <aroulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 16:59:51 by aroulin           #+#    #+#             */
/*   Updated: 2017/12/03 12:38:53 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include <sh.h>
# include "enum.h"

/*
**			LEXING
*/

# define CHILD(x) (x >= 0 && x < MAX_CHILD) ? true : false
# define INIT 2

# define SINGLE_QUOTE 2
# define DOUBLE_QUOTE 4
# define DQ 4
# define BACKSLASH 8

# define TOKEN 1
# define OPERATER 2

# define SYNTAX_ERR 666
# define ENV_ERR 667
# define FILE_404 668
# define EXE_403 669
# define NOT_DIR 670

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

# define OPT_P						1
# define OPT_S						4
# define OPT_L						8
# define OPT_C						16
# define OPT_F						32
# define OPT_G						64
# define OPT_U						128
# define OPT_K						256
# define OPT_H						512
# define OPT_B						1024
# define OPT_E						2048
# define OPT_J						4096
# define OPT_R						8192
# define OPT_A						16384
# define FORK						1
# define FOREGROUND					2
# define WRITE_PREVIOUS				4
# define DONT_EXECUTE				8
# define FORCE_FORK					16

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
# define H_HB					"-a                      : usage hash\n"
# define H_HH					"-h                      : usage history\n"
# define H_HK					"-k                      : usage kill\n"
# define H_HS					"-s                      : usage setenv\n"
# define H_HU					"-u                      : usage unsetenv\n"
# define H_HF					"-f                      : usage foreground\n"
# define H_HG					"-b                      : usage background\n"
# define H_HC					"-c                      : usage cd\n"
# define H_HM					"-r                      : usage readline\n"

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
# define ALIAS					"alias: "
# define S42H					"42sh: "
# define UNSETENV				"unsetenv : "
# define SETENV					"setenv : "
# define BECHO					"echo : "
# define UCD					"cd : "
# define UHELP					"help : "

# define LIMIT					"limit process at 1024"
# define BAD_FD					" Bad file descriptor"
# define JOBS_IN_BG				"job already in background"
# define NEED_VALUE				"variable need a name : "
# define JOBS_NOT_FOUND			"job not found: "
# define INVALID				"invalid argument : "
# define NO_ARGS_U				"option requires an argument -- u"
# define VAR_NO_SET				"variable not set : "
# define WRONG_FORMAT			"variable have wrong format : "
# define BAD_OPTION				"option not found : "
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
# define CONT				"Continued"
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
