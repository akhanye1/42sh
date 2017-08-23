/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 12:40:48 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/17 08:54:29 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

static void	print_env(char *str, t_env *env)
{
	char	*var;

	if (!(var = get_envvalue(str, env)))
		return ;
	ft_putendl(var);
}

int			ft_echo(char **cmd, t_env *env)
{
	if (!cmd[1])
		return (0);
	if (cmd[1][0] == '$')
	{
		print_env(cmd[1] + 1, env);
	}
	else
		ft_putendl(cmd[1]);
	return (1);
}
