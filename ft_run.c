/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:40:48 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/17 09:08:17 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void		getfullname(char *path, char *name, char *buf)
{
	ft_bzero(buf, MAXWDIR);
	ft_strcat(buf, path);
	ft_strcat(buf, "/");
	ft_strcat(buf, name);
}

static int		runprog(char *buf, char **cmd, char **envi)
{
	pid_t	father;
	int		status;

	father = fork();
	if (father > 0)
		waitpid(father, &status, WUNTRACED | WCONTINUED);
	if (father == 0)
		execve(buf, cmd, envi);
	return (0);
}

static int		runfromenv(char **cmd, char **envi)
{
	int	all;
	int	i;

	if (cmd[0][0] == '/')
	{
		all = 1;
		i = -1;
		while (cmd[0][++i] && all)
		{
			if (cmd[0][i] != '/')
				all = 0;
		}
		if (all)
		{
			ft_putstr("zsh: permission denied: ");
			ft_putendl(cmd[0]);
			return (0);
		}
	}
	if (access(cmd[0], F_OK) != 0)
		return (1);
	return (runprog(cmd[0], cmd, envi));
}

static int		prepare_prog(char **paths, char **cmd, char *buf, t_env *env)
{
	int			i;

	i = -1;
	while (paths[++i])
	{
		getfullname(paths[i], cmd[0], buf);
		if (access(buf, F_OK) == 0)
		{
			ft_freestrsplit(paths);
			return (runprog(buf, cmd, env->env));
		}
	}
	ft_freestrsplit(paths);
	return (1);
}

int				ft_run(char **cmd, t_env *env)
{
	char		**paths;
	int			i;
	char		buf[MAXWDIR];

	if (cmd == NULL)
		return (1);
	i = -1;
	if (cmd[0][0] == '/' || cmd[0][0] == '.')
		return (runfromenv(cmd, env->env));
	paths = NULL;
	while (env->env[++i])
	{
		if (ft_strstr(env->env[i], "PATH="))
			paths = ft_strsplit(env->env[i] + 5, ':');
	}
	if (paths == NULL)
		return (1);
	return (prepare_prog(paths, cmd, buf, env));
}
