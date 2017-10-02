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

static void				personnal_command(char *command[], int fdout, int fderr)
{
	pid_t 		father;
	int			status;

	father = fork();
	if (father == -1)
		puterror("fork");
	else if (father)
		waitpid(father, &status, 0);
	else
	{
		dup2(fdout, STDOUT_FILENO);
		dup2(fderr, STDERR_FILENO);
		execve(command[0], command, NULL);
		exit(EXIT_FAILURE);
	}
}
 static size_t            get_str_from_branch(char **prompt, int fderr)
{
	static char		*command[] = {"/usr/bin/git", "branch", NULL};
	char			*line;
	int				fdout;
	size_t			len;

	if ((fdout = open(PATH_GIT, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		return (0);
	personnal_command(command, fdout, fderr);
	if ((fdout = open(PATH_GIT, O_RDONLY)) == -1)
		return (0);
	while (my_gnl(fdout, &line) == 1 && line[0] != '*')
		ft_memdel((void **)&line);
	if ((len = ft_strlen(line)))
    {
		(*prompt) = (char *)ft_realloc((void **)prompt, ft_strlen(*prompt), ft_strlen("\x1B[31m git[\x1B[32m\x1B[31m]") + len - 1);
        ft_strcpy((*prompt) + ft_strlen((*prompt)), "\x1B[31m git[\x1B[32m");
        ft_strcpy((*prompt) + ft_strlen((*prompt)), line + 2);
        ft_strcpy((*prompt) + ft_strlen((*prompt)), "\x1B[31m]");
    }
	ft_memdel((void **)&line);
	remove(PATH_GIT);
	close(fdout);
    return (len ? (6 + len - 2) : len);
}

static size_t		get_str_from_pwd(char **prompt, int fderr)
{
	static char	*command[] = {"/bin/pwd", NULL};
	char        *line;
	size_t		len;
	int         fdout;

	if ((fdout = open(PATH_PWD, O_CREAT | O_TRUNC | O_WRONLY, 0644)) == -1)
		return (0);
	personnal_command(command, fdout, fderr);
	if ((fdout = open(PATH_PWD, O_RDONLY)) == -1)
		return (0);
	if ((my_gnl(fdout, &line)) != 1)
		return (0);
    len = ft_strlen(line) - 1;
	while (line[len] != '/')
		len--;
	(*prompt) = (char *)ft_realloc((void **)prompt, ft_strlen(*prompt), ft_strlen(*prompt) + (len) ? len : 1);
	ft_strcpy((*prompt) + ft_strlen((*prompt)), line + (len ? len + 1 : len));
	len = ft_strlen(line + (len ? len + 1 : len));
	ft_memdel((void **)&line);
	remove(PATH_PWD);
    return (len ?  : 1);
}

void			init_prompt(void)
{
	int				fderr;
    static char		*prompt;
    size_t			len;

	fderr = open(PATH_ERR, O_WRONLY);
	len = 3;
	prompt = (char *)ft_realloc((void **)&prompt, 0, ft_strlen("\x1B[1m\x1B[34m"));
	ft_strcpy(prompt, "\x1B[1m\x1B[34m");
	len += get_str_from_pwd(&prompt, fderr);
    len += get_str_from_branch(&prompt, fderr);
	prompt = (char *)ft_realloc((void **)&prompt, ft_strlen(prompt),
		ft_strlen(prompt) + ft_strlen("\x1B[31m √ \x1B[0m"));
	ft_strcpy(prompt + ft_strlen(prompt), var_return(424242) ? GRN : RED);
    ft_strcpy(prompt + ft_strlen(prompt), " √ \x1B[0m");
	my_prompt(prompt);
    get_len_prompt((int)len);
	(prompt) = NULL;
    close(fderr);
}
