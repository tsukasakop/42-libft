/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 01:20:58 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/29 19:58:10 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	s_needle;
	size_t	i;
	size_t	j;
	size_t	s_haystack;

	if (len == 0)
	{
		if (haystack && *needle == '\0')
			return ((char *)haystack);
		else
			return (NULL);
	}
	i = 0;
	s_haystack = ft_strlen(haystack);
	s_needle = ft_strlen(needle);
	while (i + s_needle <= s_haystack && i + s_needle <= len)
	{
		j = 0;
		while (j < s_needle && haystack[i + j] == needle[j])
			j++;
		if (j == s_needle)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}
/*

#include <stdio.h>
#include <string.h>

void	test(const char *h, const char *n, size_t l)
{
	printf("arg: h=%s, n=%s, l=%zu\n", h, n, l);
	printf("org: %p, %ld\n", strnstr(h, n, l), strnstr(h, n, l) - h);
	printf("slf: %p, %ld\n\n", ft_strnstr(h, n, l), ft_strnstr(h, n, l) - h);
}

int	main(void)
{
	char*s="1234567890";
	test("1234567890", "234", 2);
	test("1234567890", "234", 3);
	test("1234567890", "234", 4);
	test("1234567890", "234", 5);
	test("1234567890", "234", 10);
	test("1234567890", "234", 0);
	test("1234567890", "234", 11);
	test("1234567890", "234", -1);
	test("1234567890", "23456789012", 0);
	test("1234567890", "", 10);
	test(s,s+5,10);
	test("1234567890", "234", 10);
	test("1234567890", "234", 10);
	test("1234567890", "234", 10);
	test("1234567890", "234", 10);
	test("", "", 0);
	test(NULL, "1", 0);
	test("1234567890", "", 0);
	//test("1", NULL, 0);
} //*/
