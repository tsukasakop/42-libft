/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:55:56 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/27 12:45:25 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stddef.h>
#include <stdlib.h>
void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	
	if (size && count > SIZE_MAX / size)
		return (NULL);
	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_memset(p, 0, count * size);
	return (p);
}
/*
#include <limits.h>
#include <stdio.h>

int	main(void)
{
	char	*c;
	size_t	i;
	size_t	t;

	t = (size_t)SIZE_MAX / 10 + (size_t)1;
	c = (char *)calloc(t, 10);
	i = 0;
	while (i < 1 && c[i] == 0)
		i++;
	printf("%zu", t);
}
//*/
