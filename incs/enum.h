//
// Created by Alexandre ROULIN on 11/13/17.
//

#ifndef ENUM_H
# define ENUM_H

typedef enum 			e_value
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
	VALUE_LESS_AND,
	VALUE_GREAT_AND
}						t_value;

/*
**			TOKEN RECOGNITION
*/

typedef enum 			e_priority
{
	PRIO_SEPARATOR,
	PRIO_AMPERSAND,
	PRIO_CMD_AND_OR,
	PRIO_PIPE,
	PRIO_REDIR,
	PRIO_COMMAND
}						t_priority;

#endif
