/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:40:48 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/17 08:58:10 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

int			ft_setenv(char **cmd, t_env *envv)
{
	char			var[MAXWDIR];
	char			newval[MAXWDIR];
	int				i;

	if (cmd == NULL || !cmd[1])
		return (1);
	i = 0;
	while (envv->env[i])
		i++;
	if (ft_strchr(cmd[1], '='))
	{
		i = ft_strchr(cmd[1], '=') - cmd[1];
		ft_strncpy(var, cmd[1], i);
		var[i] = '\0';
		ft_strcpy(newval, cmd[1] + (i + 1));
		if (updateenv(var, newval, envv) == 0)
			setnewenv(var, newval, envv);
	}
	else if (cmd[1] || cmd[2])
	{
		if (updateenv(cmd[1], cmd[2], envv) == 0)
			setnewenv(cmd[1], cmd[2], envv);
	}
	return (0);
}
