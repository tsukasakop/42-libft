/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:39:36 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/29 20:02:24 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*p;
	size_t	i;

	n = (ft_strlen(s) > start) * ft_strlen((char *)s + start);
	n -= (n - len) * (len < n);
	p = malloc(n + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p[i] = s[start + i];
		i++;
	}
	p[n] = '\0';
	return (p);
}
