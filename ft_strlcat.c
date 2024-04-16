/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 05:22:29 by tkondo            #+#    #+#             */
/*   Updated: 2024/01/29 11:30:01 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:16:43 by tkondo            #+#    #+#             */
/*   Updated: 2024/01/19 04:50:30 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	i;

	dest_len = 0;
	src_len = 0;
	i = 0;
	while (dest[dest_len] != '\0')
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
