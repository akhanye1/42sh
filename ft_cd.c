/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:40:48 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/17 08:55:36 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static int	invalid_dir(char *name)
{
	ft_putstr("cd: no such file or directory: ");
	ft_putendl(name);
	return (0);
}

static void	update_pwd(t_env *envv, char *oldwd)
{
	char	wkdir[MAXWDIR];

	getcwd(wkdir, MAXWDIR);
	updateenv("PWD", wkdir, envv);
	updateenv("OLDPWD", oldwd, envv);
}

int			ft_cd(char **cmd, t_env *env)
{
	int		r;
	char	oldwd[MAXWDIR];

	getcwd(oldwd, MAXWDIR);
	if (!cmd[1])
	{
		if ((r = chdir(env->wd)) == -1)
			return (invalid_dir(cmd[1]));
	}
	else if (ft_strcmp(cmd[1], "~") == 0)
	{
		if ((r = chdir(env->wd)) == -1)
			return (invalid_dir(cmd[1]));
	}
	else if (ft_strcmp(cmd[1], "-") == 0)
	{
		if ((r = chdir(get_envvalue("OLDPWD", env))) == -1)
			return (invalid_dir(cmd[1]));
	}
	else if ((r = chdir(cmd[1])) == -1)
		return (invalid_dir(cmd[1]));
	update_pwd(env, oldwd);
	return (0);
}
