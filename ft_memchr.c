/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 11:38:57 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/27 11:41:34 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	const char		*c_s = (const char *)s;
	unsigned char	uc;

	uc = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (c_s[i] == uc)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
