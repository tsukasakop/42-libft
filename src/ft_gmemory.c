/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gmemory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:05:23 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/19 17:05:25 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

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
