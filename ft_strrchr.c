/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:58:14 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/27 19:18:45 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s) - 1;
	if (c == '\0')
		return ((char *)s + i + 1);
	while (1)
	{
		if (!((s[i] ^ c) & 255))
			return ((char *)s + i);
		if (i == 0)
			return (NULL);
		i--;
	}
}
/*
#include <stdio.h>
#include <string.h>

void	test(char *s, int c)
{
	printf("arg: s=%s, c=%d, mem=%p\n", s, c, s);
	printf("org: %p\n", strrchr(s, c));
	printf("slf: %p\n\n", ft_strrchr(s, c));
}
int	main(void)
{
	char* s= "libft-test-tokyo";
	test("123", '1');
	test("123", '3');
	test("123", 0);
	test("123", '0');
	test("", '3');
test(s,'s');
}
//*/
