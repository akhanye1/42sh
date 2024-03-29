/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:40:48 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/15 13:38:23 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int		ft_env(char **cmd, t_env *env)
{
	int			i;

	i = -1;
	if (cmd)
		while (env->env[++i])
			ft_putendl(env->env[i]);
	return (0);
}
