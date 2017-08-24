/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getval.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 13:12:05 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/24 13:54:32 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	updateval(char *env, char *comp, char *val)
{
	ft_strcpy(env, comp);
	ft_strcat(env, "=");
	ft_strcat(env, val);
}

static void	setcomp(char *env, char *comp)
{
	ft_strcpy(env, comp);
	ft_strcat(env, "=");
}

int			setnewenv(char *var, char *newvar, t_env *envv)
{
	char	buff[MAXWDIR];

	updateval(buff, var, newvar);
	duplicate_new(envv, buff);
	return (0);
}

int			updateenv(char *cmp, char *newvar, t_env *envv)
{
	int		i;
	char	buff[MAXWDIR];
	char	find[MAXWDIR];

	i = -1;
	setcomp(find, cmp);
	updateval(buff, cmp, newvar);
	while (envv->env[++i])
	{
		if (ft_strncmp(envv->env[i], find, ft_strlen(find)) == 0)
		{
			free(envv->env[i]);
			envv->env[i] = ft_strdup(buff);
			return (1);
		}
	}
	return (0);
}

char		*get_envvalue(char *var, t_env *envv)
{
	int		i;
	char	buff[MAXWDIR];

	i = -1;
	setcomp(buff, var);
	while (envv->env[++i])
	{
		if (ft_strncmp(envv->env[i], buff, ft_strlen(buff)) == 0)
			return (envv->env[i] + (ft_strlen(buff)));
	}
	return (NULL);
}
