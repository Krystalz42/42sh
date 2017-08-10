/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/09 23:25:58 by aroulin           #+#    #+#             */
/*   Updated: 2017/08/10 02:33:02 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

/*
**			INITIALIZATION FLAGS
*/

# define ENV_NULL	1
# define ENV_INIT	2
# define ENV_REC	4

# define OLD_TERM	1
# define OUR_TERM	2
# define SAVE_OLD	4
# define SAVE_OUR	8

/*
**			INITIALIZATION READ
*/

# define SPECIAL_KEY		'\x1B'
# define DELETE_KEY			'\x1F'
# define EOF_KEY			'\x4'
# define TAB_KEY			'\x9'
# define ENTER_KEY			'\xD'
# define CLEAR_KEY			'\xC'
# define INTERRUPT_KEY		'\x2'

# define ARROW_DOWN			'\x42'
# define ARROW_LEFT			'\x44'
# define ARROW_UP			'\x41'
# define ARROW_RIGHT		'\x43'
# define END_KEY			'\x46'
# define HOME_KEY			'\x48'
# define DEL_KEY			'\x33'

# define SHIFT_UP_KEY		'\x41'
# define SHIFT_DOWN_KEY		'\x42'
# define SHIFT_RIGHT_KEY	'\x43'
# define SHIFT_LEFT_KEY		'\x44'

# define PRINT_KEY(x) (x >= '\x20' && x <= '\x7E')

#endif
