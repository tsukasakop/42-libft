/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:08:39 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/19 16:28:07 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_stdlib.h"
#include <stdlib.h>

static t_blocked_node	*ft_bnnew(void)
{
	return ((t_blocked_node *)ft_calloc(sizeof(t_blocked_node), 1));
}

static int	ft_bnadd(t_blocked_node *bn, void *ptr)
{
	while (bn->cnt == BN_STORE_MAX && bn->next)
	{
		if (!bn->next)
		{
			bn->next = ft_bnnew();
			if (!bn->next)
				return (0);
		}
		bn = bn->next;
	}
	bn->p[bn->cnt] = ptr;
	bn->cnt += 1;
	return (1);
}

void	ft_bnfree_shallow(t_blocked_node *bn)
{
	t_blocked_node	*cur;
	t_blocked_node	*tmp;
	size_t			i;

	cur = bn;
	while (cur)
	{
		i = 0;
		while (i < cur->cnt)
		{
			free(cur->p[i]);
			i++;
		}
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}
}

t_memory_manager	*ft_mmnew(void)
{
	t_memory_manager	*(*_mmnew)(void);

	_mmnew = ft_bnnew;
	return ((t_memory_manager *)_mmnew());
}

int	ft_mmadd(t_memory_manager *mm, void *ptr)
{
	int	(*_mmadd)(t_memory_manager *, void *);

	_mmadd = ft_bnadd;
	if (!mm)
		return (0);
	return (_mmadd(mm, ptr));
}

void	*ft_mmmalloc(t_memory_manager *mm, size_t size)
{
	void	*p;

	if (!mm)
		return (NULL);
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

	if (!mm)
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
	void	(*_mmfree)(t_memory_manager *);

	_mmfree = ft_bnfree_shallow;
	if (!mm)
		return ;
	_mmfree(mm);
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
		return (0);
	return (ft_mmadd(mm, ptr));
}

void	*ft_g_mmmalloc(size_t size)
{
	t_memory_manager	*mm;

	mm = ft_g_mmget();
	if (!mm)
		return (NULL);
	return (ft_mmmalloc(mm, size));
}

void	*ft_g_mmcalloc(size_t size, size_t cnt)
{
	t_memory_manager	*mm;

	mm = ft_g_mmget();
	if (!mm)
		return (NULL);
	return (ft_mmcalloc(mm, size, cnt));
}

void	ft_g_mmfree(void)
{
	t_memory_manager	*mm;

	mm = ft_g_mmget();
	if (!mm)
		return ;
	return (ft_mmfree(mm));
}
