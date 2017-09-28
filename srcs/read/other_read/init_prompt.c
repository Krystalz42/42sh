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

static void			my_pwd(int fderr)
{
    static char	*command[] = {"/bin/pwd", NULL};
    pid_t	    father;
    int         fdout;

    fdout = open(PATH_PWD, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if ((father = fork()) == -1)
        return ;
    if (!father)
    {
        dup2(fdout, STDOUT_FILENO);
	    dup2(fderr, STDERR_FILENO);
        execve(command[0], command, NULL);
	    exit(EXIT_FAILURE);
    }
    else
        wait(&father);
    close(fdout);
}

static inline void			git_branch(int fderr)
{
	static char	*command[] = {"/usr/bin/git", "branch", NULL};
	pid_t	    father;
    int         fdout;

	(void)command;
	fdout = open(PATH_GIT, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    if ((father = fork()) == -1)
        return ;
    if (!father)
    {
	    dup2(fdout, STDOUT_FILENO);
        dup2(fderr, STDERR_FILENO);
        execve(command[0],command, NULL);
	    perror("");
	    exit(EXIT_FAILURE);
    }
    else
        wait(&father);
	close(fdout);
}

static int            get_str_from_branch(char **prompt, int fderr)
{
	char		*line;
    static int	fd;
    int         len;
	char        *tmp;

    git_branch(fderr);
    fd = open(PATH_GIT, O_RDONLY);
	while (my_gnl(fd, &line))
	{
		(line[0] == '*') && (tmp = ft_strdup(line));
		free(line);
	}
	if ((len = ft_strlen(tmp)))
    {
        ft_strcpy((*prompt) + ft_strlen((*prompt)), "\x1B[31m git[\x1B[32m");
        ft_strcpy((*prompt) + ft_strlen((*prompt)), tmp + 2);
        ft_strcpy((*prompt) + ft_strlen((*prompt)), "\x1B[31m]");
    }
	free(tmp);
	remove(PATH_GIT);
	close(fd);
    return (len ? (6 + len - 2) : len);
}

static int          get_str_from_pwd(char **prompt, int fderr)
{
    char        *tmp;
    int         i;
    int         s;
	int         fd;

    tmp = NULL;
    my_pwd(fderr);
    fd = open(PATH_PWD, O_RDONLY);
    my_gnl(fd, &tmp);
    s = 0;
    i = -1;
    while (tmp && tmp[++i])
        if (tmp[i] == '/')
            s = i;
    ft_strcpy((*prompt) + ft_strlen(*prompt), (!s) ? tmp : tmp + s + 1);
    s = ft_strlen(tmp + s + 1);
    free(tmp);
	remove(PATH_PWD);
    close(fd);
    return (!s ? 1 : s);
}

void			init_prompt(void)
{
	static int      fderr = 0;
    static char    	*prompt;
    int             i;
    int             len;

    i = -1;
    len = 3;
	fderr = open(PATH_ERR, O_WRONLY);
	(!prompt) ? prompt = (char *)ft_memalloc(127) : ft_bzero(prompt, 127);
    ft_strcpy(prompt, "\x1B[1m\x1B[34m");
    len += get_str_from_pwd(&prompt, fderr);
    len += get_str_from_branch(&prompt, fderr);
	ft_strcpy(prompt + ft_strlen(prompt), var_return(424242) ? GRN : RED);
    ft_strcpy(prompt + ft_strlen(prompt), " √ \x1B[0m");
	my_prompt(prompt);
    get_len_prompt(len);
    close(fderr);
}
