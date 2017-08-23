/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memtrace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhanye <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 15:15:35 by akhanye           #+#    #+#             */
/*   Updated: 2017/07/30 17:23:51 by akhanye          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minishell.h"

void	freeallmem(t_mem **mem)
{
	t_mem	*temp;
	t_mem	*ptemp;

	if ((*mem) == NULL)
		return ;
	temp = (*mem);
	while (temp)
	{
		ptemp = temp;
		temp = temp->next;
		free(ptemp->mem);
		if (ptemp->ppmem)
			free(ptemp->ppmem);
		free(ptemp);
	}
}

void	remove_stack(t_mem **mem, char *tmem)
{
	t_mem	*temp;
	t_mem	*ptemp;

	if ((*mem) == NULL)
		return ;
	temp = (*mem);
	ptemp = NULL;
	while (temp)
	{
		if (tmem == temp->mem)
		{
			free(tmem);
			if (temp->ppmem)
				free(temp->ppmem);
			if (!ptemp)
				(*mem) = temp->next;
			else
				ptemp->next = temp->next;
			free(temp);
			break ;
		}
		ptemp = temp;
		temp = temp->next;
	}
}

void	add_tostack(t_mem **mem, char *tmem, char **ptemp)
{
	t_mem	*temp;

	if (!(temp = (t_mem*)malloc(sizeof(t_mem) * 1)))
		return ;
	temp->mem = tmem;
	temp->ppmem = ptemp;
	temp->next = NULL;
	if ((*mem) == NULL)
		(*mem) = temp;
	else
	{
		temp->next = (*mem);
		(*mem) = temp;
	}
}
