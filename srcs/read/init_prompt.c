/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prompt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 17:45:51 by aroulin           #+#    #+#             */
/*   Updated: 2017/09/14 17:45:52 by aroulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sh.h>

void			my_pwd(void)
{
    static char	*command[] = {"/bin/pwd"};
    pid_t	    father;
    int         fdout;
    int         fderr;

    fdout = open("/tmp/.pwd_info", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    fderr = open("/tmp/.pwd_info_err", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if ((father = fork()) == -1)
        return ;
    if (!father)
    {
        dup2(fdout, STDOUT_FILENO);
        dup2(fderr, STDERR_FILENO);
        execve(command[0], command, NULL);
        exit(1);
    }
    else
        wait(&father);
    close(fderr);
    close(fdout);
}

static void			git_branch(void)
{
    static char	*command[] = {"/usr/bin/git", "branch"};
    pid_t	    father;
    int         fdout;
    int         fderr;

    fdout = open("/tmp/.git_info", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    fderr = open("/tmp/.git_info_err", O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if ((father = fork()) == -1)
        return ;
    if (!father)
    {
        dup2(fdout, STDOUT_FILENO);
        dup2(fderr, STDERR_FILENO);
        execve(command[0], command, NULL);
        exit(1);
    }
    else
        wait(&father);
    close(fderr);
    close(fdout);
}

static char            *get_str_from_branch(void)
{
    char		*line;
    int			fd;
    char        *tmp;

    line = NULL;
    git_branch();
    fd = open("/tmp/.git_info", O_RDONLY);
    get_next_line(fd, &line);
    tmp = ft_strdup(line + 2);
    free(line);
    close(fd);
    remove("/tmp/.git_info");
    return (tmp);
}

static char             *get_str_from_pwd(void)
{
    char        *tmp;
    int         i;
    int         s;
    int fd;

    tmp = NULL;
    my_pwd();
    fd = open("/tmp/.pwd_info", O_RDONLY);
    get_next_line(fd, &tmp);
    s = 0;
    i = -1;
    while (tmp[++i])
        if (tmp[i] == '/')
            s = i;
    remove("/tmp/.pwd_info");
    return ((!s ? ft_strdup("/") : ft_strdup(tmp + s + 1)));
}

void			init_prompt(void)
{
    static char		*prompt;
    char	    	*tmp;
    int             i;

    i = -1;
    if (!prompt)
        prompt = (char *)ft_memalloc(sizeof(char) * 127);
    ft_strcpy(prompt + ft_strlen(prompt), "\x1B[1m\x1B[34m");
    if ((tmp = get_str_from_pwd()))
    {
        ft_strcpy(prompt + ft_strlen(prompt), tmp);
        free(tmp);
    }
    if ((tmp = get_str_from_branch()) && ft_strlen(tmp))
    {
        ft_strcpy(prompt + ft_strlen(prompt), "\x1B[31m git[\x1B[32m");
        ft_strcpy(prompt + ft_strlen(prompt), tmp);
        ft_strcpy(prompt + ft_strlen(prompt), "\x1B[31m]");
        free(tmp);
    }
    ft_strcpy(prompt + ft_strlen(prompt), " √ \x1B[0m");
    my_prompt(prompt);
}
