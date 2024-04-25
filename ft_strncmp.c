/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 04:53:19 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/25 18:45:20 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0 && (*s1 || *s2))
	{
		if ((*s1 ^ *s2) & 255)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
/*
#include <string.h>
int main() {
    char str1[] = "Hello";
    char str2[] = "Hell";
str1[2]=127;
str2[2]=-128;
    int result = ft_strncmp(str1, str2, -4);
    int result2 = strncmp(str1, str2, -4);

    printf("Comparison result: %d\n", result);
    printf("Comparison result2: %d\n", result2);

    return 0;
}//*/
