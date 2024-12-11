/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:08:39 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/11 14:16:42 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include <stdlib.h>

t_node	**get_mm(void)
{
	static t_node	**mm;

	if (!mm)
		mm = (t_node **)calloc(sizeof(t_node *), 1);
	return (mm);
}

int	ft_mmadd(void *ptr)
{
	static t_node	**p;
	t_node			*mmnode;

	if (!p)
	{
		if (!get_mm())
			return (0);
		p = get_mm();
	}
	mmnode = (t_node *)calloc(sizeof(t_node), 1);
	if (!mmnode)
		return (0);
	mmnode->p = ptr;
	if (!*p)
		*p = mmnode;
	else
		(*p)->next = mmnode;
	p = &(*p)->next;
	return (1);
}

void	*ft_mmmalloc(size_t size)
{
	void	*p;

	p = malloc(size);
	if (!p)
		return (NULL);
	if (!ft_mmadd(p))
	{
		free(p);
		return (NULL);
	}
	return (p);
}

void	*ft_mmcalloc(size_t cnt, size_t size)
{
	void	*p;

	p = calloc(cnt, size);
	if (!p)
		return (NULL);
	if (!ft_mmadd(p))
	{
		free(p);
		return (NULL);
	}
	return (p);
}

void	ft_mmfree(void)
{
	t_node	**mm;
	t_node	*i;
	t_node	*tmp;

	mm = get_mm();
	if (!mm)
		return ;
	i = *mm;
	while (i)
	{
		tmp = i->next;
		free(i->p);
		free(i);
		i = tmp;
	}
	free(mm);
}
