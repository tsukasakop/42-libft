/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:19:42 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/26 17:03:09 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*c_dst;
	const char	*c_src;

	c_src = (const char *)src;
	c_dst = (char *)dst;
	while (n)
	{
		c_dst[n - 1] = c_src[n - 1];
		n--;
	}
	return (dst);
}
