/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:58:14 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/09 05:19:31 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + i);
	while (1)
	{
		if (!((s[i - 1] ^ c) & 255))
			return ((char *)s + i - 1);
		if (i == 0)
			return (NULL);
		i--;
	}
}
