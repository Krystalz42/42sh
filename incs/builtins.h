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
uint8_t			ft_cd(t_node *node, int info);
signed int		search_in_tab(char **data, char *var);
char			**refresh_varenv(char **env);
char			*ft_path(char *var, unsigned int begin);
char			*add_envar(char *var, char *value);
char			**init_pwd(char **env);

/*
** ECHO
*/
uint8_t			ft_echo(t_node *node, int info);

/*
** ENV, SETENV, UNSETENV
*/
uint8_t			ft_env(t_node *node, int info);
uint8_t			ft_setenv(t_node *node, int info);
unsigned int	search_char(char *str, char c);
uint8_t			ft_unsetenv(t_node *node, int info);

/*
** UTILS
*/
uint8_t			var_return(int ret);
int				ft_error(char *var, char *msg, int ret);
unsigned int	tablen(char **src);

#endif
