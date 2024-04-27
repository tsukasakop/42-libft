/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:16:43 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/27 19:18:25 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dest && dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (dest_len >= size)
		return (src_len + size);
	if (dest_len < size - 1)
	{
		while (src[i] != '\0' && dest_len < size - 1)
		{
			dest[dest_len] = src[i];
			dest_len++;
			i++;
		}
		dest[dest_len] = '\0';
	}
	return (src_len + dest_len - i);
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
