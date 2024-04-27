/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 16:19:42 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/27 11:32:35 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*c_dst;
	const char	*c_src;
	char		sign;
	size_t		cur;

	c_src = (const char *)src;
	c_dst = (char *)dst;
	sign = (dst < src) * 2 - 1;
	cur = (sign == -1) * len;
	while (cur != (sign == 1) * len)
	{
		c_dst[cur - (sign == -1)] = c_src[cur - (sign == -1)];
		cur += sign;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_dst(void *dst, size_t size)
{
	for (size_t i = 0; i < size; i++)
		printf("%c", ((char *)dst)[i]);
	printf("\n");
}
void	check_memmove(void *dst, void *src, size_t size)
{
	void	*expected;

	expected = malloc(size);
	memmove(expected, src, size);
	ft_memmove(dst, src, size);
	if (expected)
		free(expected);
}
int	main(void)
{
	char *src;
	char *dst;

	src = malloc(127 - 32);
	for (int i = 32; i < 127; i++)
		src[i - 32] = i;
	src[127 - 32] = 0;
	dst = malloc(127 - 32);
	memmove(dst, src, 100);
	print_dst(dst, 96);
	//check_memmove(dst, dst + 20, 45);
	check_memmove(dst + 20 , dst, 45);
	print_dst(dst, 96);
} //*/
