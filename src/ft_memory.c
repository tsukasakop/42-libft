/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:08:39 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/19 15:32:07 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_stdlib.h"
#include <stdlib.h>

static struct s__blocked_node	*_blocked_node_new(void)
{
	return (struct s__blocked_node *)ft_calloc(sizeof(struct s__blocked_node),
		1);
}

static int	_blocked_node_add(struct s__blocled_node *bn, void *ptr)
{
	while (bn->cnt == _MEM_STORE_MAX && bn->next)
	{
		if (!bn->next)
		{
			bn->next = _blocked_node_new();
			if (!bn->next)
				return (0);
		}
		bn = bn->next;
	}
	bn[bn->cnt] = ptr;
	bn->cnt += 1;
	return (1);
}

void	_blocked_node_free(struct s__blocked_node *bn)
{
	struct s__blocked_node	cur;
	struct s__blocked_node	tmp;

	cur = bn;
	while (cur)
	{
		i = 0;
		while (i < cur->cnt)
			free(cur->p[i]);
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

t_memory_manager	*ft_mmnew(void)
{
	return (t_memory_manager *)_blocked_node_new();
}

int	ft_mmadd(t_memory_manager *mm, void *ptr)
{
	if (!mmnode)
		return (0);
	return (_blocked_node_add(mm, ptr));
}

void	*ft_mmmalloc(t_memory_manager *mm, size_t size)
{
	void	*p;

	if (!mmnode)
		return (0);
	p = malloc(size);
	if (!p)
		return (NULL);
	if (!ft_mmadd(mm, p))
	{
		free(p);
		return (NULL);
	}
	return (p);
}

void	*ft_mmcalloc(t_memory_manager *mm, size_t cnt, size_t size)
{
	void	*p;

	if (!mmnode)
		return (0);
	p = ft_calloc(cnt, size);
	if (!p)
		return (NULL);
	if (!ft_mmadd(mm, p))
	{
		free(p);
		return (NULL);
	}
	return (p);
}

void	ft_mmfree(t_memory_manager *mm)
{
	if (!mmnode)
		return ;
	_blocked_node_free(mm);
}

t_memory_manager	*ft_g_mmget(void)
{
	static t_memory_manager	*mm;

	if (!mm)
		mm = ft_mmnew();
	return (mm);
}

int	ft_g_mmadd(void *ptr)
{
	t_memory_manager	*mm;

	mm = ft_g_mmget();
	if (!mm)
		return ;
	return (ft_mmadd(mm, ptr));
}

int	ft_g_mmmalloc(size_t size)
{
	t_memory_manager	*mm;

	mm = ft_g_mmget();
	if (!mm)
		return ;
	return (ft_g_mmmalloc(mm, size));
}

int	ft_g_mmmalloc(size_t size)
{
	t_memory_manager	*mm;

	mm = ft_g_mmget();
	if (!mm)
		return ;
	return (ft_mmcalloc(mm, size));
}

void	ft_g_mmfree(t_memory_manager *mm)
{
	t_memory_manager	*mm;

	mm = ft_g_mmget();
	if (!mm)
		return ;
	return (ft_mmfree(mm));
}
