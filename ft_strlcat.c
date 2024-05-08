/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:16:43 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/09 05:18:41 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	size_t	cnt;

	cnt = 0;
	while (cnt < maxlen && s[cnt])
		cnt++;
	return (cnt);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	cpy_len;

	dst_len = ft_strnlen(dst, dstsize);
	src_len = ft_strlen(src);
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	if (dstsize > dst_len + src_len)
		cpy_len = src_len;
	else
		cpy_len = dstsize - dst_len - 1;
	ft_memmove(dst + dst_len, src, cpy_len);
	dst[dst_len + cpy_len] = '\0';
	return (src_len + dst_len);
}
