/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:58:14 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/17 01:03:11 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char*)s + i);
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

void	test(char *s, int c)
{
	printf("arg: s=%s, c=%d, mem=%p\n", s, c, s);
	printf("org: %p\n", strchr(s, c));
	printf("slf: %p\n\n", ft_strchr(s, c));
}
int	main(void)
{
	test("123", '0');
	test("123", '1');
	test("123", '3');
	test("123", 0);
	test("", '3');
}
//*/
