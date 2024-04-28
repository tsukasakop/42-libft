/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:16:43 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/28 18:29:04 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	dst_len;
	unsigned int	src_len;
	unsigned int	i;

	dst_len = 0;
	src_len = 0;
	i = 0;
	while (dst && dst[dst_len] != '\0')
		dst_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dst_len >= dstsize)
		return (src_len + dstsize);
	if (dst_len < dstsize - 1)
	{
		while (src[i] != '\0' && dst_len < dstsize - 1)
		{
			dst[dst_len] = src[i];
			dst_len++;
			i++;
		}
		dst[dst_len] = '\0';
	}
	return (src_len + dst_len - i);
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
