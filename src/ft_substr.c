/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:39:36 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/09 08:06:22 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*p;

	if (s == NULL)
		return (NULL);
	n = ft_strlen(s);
	if (start)
	{
		if (n > start)
			n = start;
		return (ft_substr(s + n, 0, len));
	}
	if (len < n)
		n = len;
	p = malloc(n + 1);
	if (p == NULL)
		return (NULL);
	ft_memmove(p, s, n);
	p[n] = '\0';
	return (p);
}
