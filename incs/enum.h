/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enum.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-quel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:02:53 by jle-quel          #+#    #+#             */
/*   Updated: 2017/12/14 13:40:22 by jle-quel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENUM_H
# define ENUM_H

/*
**			INITIALIZATION READ
*/

typedef enum			e_readline
{
	REFRESH = 0,
	CTRL_A = 1,
	CTRL_B = 2,
	CTRL_D = 4,
	CTRL_E = 5,
	CTRL_F = 6,
	TAB_KEY = 9,
	CTRL_P = 16,
	CTRL_K = 11,
	CLEAR_KEY = 12,
	CTRL_N = 14,
	CTRL_R = 18,
	CTRL_UNDO = 31,
	DELETE_KEY = 127,
	PRINT_KEY = 424242,
	META_L = 27675,
	META_C = 25371,
	META_U = 29979,
	META_Y = 31003,
	META_F = 26139,
	META_D = 25627,
	META_DEL = 32539,
	META_B = 25115,
	ARROW_LEFT = 4479771,
	ARROW_DOWN = 4348699,
	ARROW_UP = 4283163,
	ARROW_RIGHT = 4414235,
	END_KEY = 4610843,
	HOME_KEY = 4741915,
	DEL_KEY = 2117294875,
	SHIFT_UP_KEY = 71683997260571,
	SHIFT_DOWN_KEY = 72783508888347,
	SHIFT_RIGHT_KEY = 73883020516123,
	SHIFT_LEFT_KEY = 74982532143899,
}						t_readline;

typedef enum			e_value
{
	VALUE_COMMAND,
	VALUE_SEMI_COLON,
	VALUE_AMPERSAND,
	VALUE_AND_IF,
	VALUE_OR_IF,
	VALUE_PIPELINE,
	VALUE_LESS,
	VALUE_GREAT,
	VALUE_DLESS,
	VALUE_DGREAT,
	VALUE_GREAT_AND,
	VALUE_LESS_AND
}						t_value;

/*
**			TOKEN RECOGNITION
*/

typedef enum			e_priority
{
	PRIO_SEPARATOR,
	PRIO_AMPERSAND,
	PRIO_CMD_AND_OR,
	PRIO_PIPE,
	PRIO_COMMAND,
	PRIO_REDIR
}						t_priority;

#endif
