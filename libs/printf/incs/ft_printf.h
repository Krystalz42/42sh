/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgraille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 15:49:27 by jgraille          #+#    #+#             */
/*   Updated: 2017/01/15 15:51:58 by jgraille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

typedef struct		s_formatidentifier
{
	char	*flag;
	char	*conv;
	char	*full_arg;
	size_t	fp;
	int		lp;
	char	sign;
	char	arg;
	char	*dif;
}					t_fmtid;

char				*fill_pointer(char *str, t_fmtid id);
char				fill_char(char *str, t_fmtid id);
char				*fill_tank(char *str, t_fmtid id);
t_fmtid				detect_pre(t_fmtid id, va_list *ap);
void				clean_struct(t_fmtid *id);
char				*clear_flag(char *flag);
char				*conv_base(t_fmtid id, va_list *ap);
char				*converted(t_fmtid id, va_list *ap);
char				*conv_un(t_fmtid id, va_list *ap);
char				*if_color(char *color);
t_fmtid				format_identifier(char **fmt);
size_t				str_special(t_fmtid id, va_list *ap);
int					ft_printf(const char *fmt, ...);
char				*cut_str(char *str, t_fmtid id);
char				*part_nu(t_fmtid id, va_list *ap);
char				*part_unsigned(t_fmtid *id, va_list *ap);
char				*part_base(t_fmtid *id, va_list *ap);
char				*part_extra(t_fmtid *id, va_list *ap);
char				*part_str(t_fmtid id, va_list *ap);
char				*part_dec(t_fmtid id, va_list *ap);
char				*fill(char *str, t_fmtid id);
char				*fill_last(char *str, t_fmtid id);
char				*fill_str(char *str, t_fmtid id);
char				*fill_hash(char *str, t_fmtid id);
char				*fill_sign(char *str, t_fmtid id);
#endif
