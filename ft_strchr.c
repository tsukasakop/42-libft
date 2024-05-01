/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:58:14 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/01 00:25:07 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	if (!((*s ^ c) & 255))
		return ((char *)s);
	if (*s)
		return (ft_strchr(s + 1, c));
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
char *s ="libft-test-tokyo";
	test("123", '0');
	test("123", '1');
	test("123", '3');
	test("123", 0);
	test("", '3');
	test(s,'l'+256);
}
//*/
