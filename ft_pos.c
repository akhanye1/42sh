/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 11:19:22 by akhanye           #+#    #+#             */
/*   Updated: 2017/08/24 13:54:27 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void		get_y_pos(t_screen *screen)
{
	int		a;
	int		i;
	char	buf[4];

	write(1, "\033[6n", 4);
	i = read(1, buf, 4);
	buf[i] = '\0';

	i = -1;
	a = 0;
	while (buf[++i])
	{
		if (buf[i] >= 48 && buf[i] <= 57)
		{
			screen->min_y = ft_atoi(&buf[i]) - 1;
			return ;
		}
	}
}
