/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:58:14 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/17 01:11:53 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*l;

	l = NULL;
	i = 0;
	while (!i || s[i - 1])
	{
		if (s[i] == c)
			l = (char *)s + i;
		i++;
	}
	return (l);
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
	test("123", '0');
	test("123", '1');
	test("123", '3');
	test("123", 0);
	test("", '3');
}
//*/
