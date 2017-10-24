/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelazou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 17:32:41 by sbelazou          #+#    #+#             */
/*   Updated: 2017/10/24 15:39:10 by sbelazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# define RETVAR(x) return(var_return(x));

//Linux
//typedef int uint8_t;

typedef struct	s_bdata
{
	char		*oldpwd;
	char		*pwd;
}				t_bdata;

/*
** SINGLETON for CD's DATA
*/
t_bdata			*b_data();

/*
** CD
*/
uint8_t			ft_cd(char **command, char **env);
signed int		search_in_tab(char **data, char *var);
char			**refresh_varenv(char **env);
char			*ft_path(char *var, unsigned int begin);
char			*add_envar(char *var, char *value);
char			**init_pwd(char **env);

/*
** ECHO
*/
uint8_t			ft_echo(char **command, char **env);

/*
** ENV, SETENV, UNSETENV
*/
uint8_t			ft_env(char **command, char **env);
uint8_t			ft_setenv(char **command, char **env);
unsigned int	search_char(char *str, char c);
uint8_t			ft_unsetenv(char **command, char **env);

/*
** UTILS
*/
uint8_t			var_return(int ret);
int				ft_error(char *var, char *msg, int ret);
unsigned int	tablen(char **src);

#endif
