/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:40:48 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/30 17:54:02 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	setcomp(char *env, char **cmd)
{
	ft_bzero(env, MAXWDIR);
	ft_strcpy(env, cmd[1]);
	ft_strcat(env, "=");
}

int			ft_unsetenv(char **cmd, t_env *env)
{
	int			i;
	char		buf[MAXWDIR];
	int			len;
	int			cnt;

	if (cmd == NULL)
		return (1);
	i = -1;
	setcomp(buf, cmd);
	len = ft_strlen(buf);
	cnt = 0;
	while (env->env[++i] && env->env[i + cnt])
	{
		if (ft_strncmp(env->env[i], buf, len) == 0)
		{
			cnt++;
			free(env->env[i]);
			if (env->env[i + cnt] == NULL)
				break ;
		}
		env->env[i] = env->env[i + cnt];
	}
	env->env[i] = NULL;
	return (0);
}
