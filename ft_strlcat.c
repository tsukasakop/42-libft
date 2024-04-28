/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:16:43 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/28 21:03:47 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

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
/* RM this line
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char			dest[100];
	char			destf[100];
	char			src[100];
	unsigned int	size;
	unsigned int	result;

	strcpy(dest, "Hello");
	strcpy(destf, "Hello");
	strcpy(src, ", world!");
	size = 20;
	printf("dest: %s\n", dest);
	printf("src : %s\n", src);
	printf("n   : %u\n", size);
	result = strlcat(dest, src, size);
	printf("return(std): %u, %s\n", result, dest);
	result = ft_strlcat(destf, src, size);
	printf("return(ft) : %u, %s\n", result, dest);
	strcpy(dest, "Hello");
	strcpy(destf, "Hello");
	strcpy(src, ", world!");
	size = 14;
	printf("dest: %s\n", dest);
	printf("src : %s\n", src);
	printf("n   : %u\n", size);
	result = strlcat(dest, src, size);
	printf("return(std): %u, %s\n", result, dest);
	result = ft_strlcat(destf, src, size);
	printf("return(ft) : %u, %s\n", result, dest);
	strcpy(dest, "Hello");
	strcpy(destf, "Hello");
	strcpy(src, ", world!");
	size = 13;
	printf("dest: %s\n", dest);
	printf("src : %s\n", src);
	printf("n   : %u\n", size);
	result = strlcat(dest, src, size);
	printf("return(std): %u, %s\n", result, dest);
	result = ft_strlcat(destf, src, size);
	printf("return(ft) : %u, %s\n", result, dest);
	strcpy(dest, "Hello");
	strcpy(destf, "Hello");
	strcpy(src, ", world!");
	size = 12;
	printf("dest: %s\n", dest);
	printf("src : %s\n", src);
	printf("n   : %u\n", size);
	result = strlcat(dest, src, size);
	printf("return(std): %u, %s\n", result, dest);
	result = ft_strlcat(destf, src, size);
	printf("return(ft) : %u, %s\n", result, dest);
	strcpy(dest, "Hello");
	strcpy(destf, "Hello");
	strcpy(src, ", world!");
	size = 2;
	printf("dest: %s\n", dest);
	printf("src : %s\n", src);
	printf("n   : %u\n", size);
	result = strlcat(dest, src, size);
	printf("return(std): %u, %s\n", result, dest);
	result = ft_strlcat(destf, src, size);
	printf("return(ft) : %u, %s\n", result, dest);
	strcpy(dest, "Hello");
	strcpy(destf, "Hello");
	strcpy(src, ", world!");
	size = 1;
	printf("dest: %s\n", dest);
	printf("src : %s\n", src);
	printf("n   : %u\n", size);
	result = strlcat(dest, src, size);
	printf("return(std): %u, %s\n", result, dest);
	result = ft_strlcat(destf, src, size);
	printf("return(ft) : %u, %s\n", result, dest);
	strcpy(dest, "Hello");
	strcpy(destf, "Hello");
	strcpy(src, ", world!");
	size = 0;
	printf("dest: %s\n", dest);
	printf("src : %s\n", src);
	printf("n   : %u\n", size);
	result = strlcat(dest, src, size);
	printf("return(std): %u, %s\n", result, dest);
	result = ft_strlcat(destf, src, size);
	printf("return(ft) : %u, %s\n", result, dest);
	strcpy(dest, "Hello");
	strcpy(destf, "Hello");
	strcpy(src, ", world!");
	size = -1;
	printf("dest: %s\n", dest);
	printf("src : %s\n", src);
	printf("n   : %u\n", size);
	result = strlcat(dest, src, size);
	printf("return(std): %u, %s\n", result, dest);
	result = ft_strlcat(destf, src, size);
	printf("return(ft) : %u, %s\n", result, dest);
	strcpy(dest, "");
	strcpy(destf, "");
	strcpy(src, "");
	size = 20;
	printf("dest: %s\n", dest);
	printf("src : %s\n", src);
	printf("n   : %u\n", size);
	result = strlcat(dest, src, size);
	printf("return(std): %u, %s\n", result, dest);
	result = ft_strlcat(destf, src, size);
	printf("return(ft) : %u, %s\n", result, dest);
	strcpy(dest, "");
	strcpy(destf, "");
	strcpy(src, "");
	size = 0;
	printf("dest: %s\n", dest);
	printf("src : %s\n", src);
	printf("n   : %u\n", size);
	result = strlcat(dest, src, size);
	printf("return(std): %u, %s\n", result, dest);
	result = ft_strlcat(destf, src, size);
	printf("return(ft) : %u, %s\n", result, dest);
}
//*/
