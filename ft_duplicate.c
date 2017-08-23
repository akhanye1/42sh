/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplicate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 13:12:14 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/17 09:08:15 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	duplicate_new(t_env *env, char *val)
{
	char		**data;
	extern char	**environ;
	int			i;

	i = 0;
	while (env->env[i])
		i++;
	if (!(data = (char**)malloc(sizeof(char*) * (i + 2))))
		return ;
	i = -1;
	while (env->env[++i])
	{
		data[i] = ft_strdup(env->env[i]);
		free(env->env[i]);
	}
	free(env->env);
	data[i] = ft_strdup(val);
	data[++i] = NULL;
	environ = data;
	env->env = data;
}

void	duplicate_environ(t_env *env)
{
	extern char	**environ;
	char		**data;
	int			i;

	i = 0;
	while (environ[i])
		i++;
	if (!(data = (char**)malloc(sizeof(char*) * (i + 1))))
		return ;
	i = -1;
	while (environ[++i])
		data[i] = ft_strdup(environ[i]);
	data[i] = NULL;
	environ = data;
	env->env = data;
}
