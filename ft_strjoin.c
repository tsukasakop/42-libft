/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:36:07 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/30 22:05:06 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	n_s1;
	size_t	n_s2;

	n_s1 = ft_strlen(s1);
	n_s2 = ft_strlen(s2);
	if (n_s1 >= SIZE_MAX - n_s1)
		return (NULL);
	p = malloc(n_s1 + n_s2 + 1);
	if (p == NULL)
		return (NULL);
	ft_memmove(p, s1, n_s1);
	ft_memmove(p + n_s1, s2, n_s2);
	ft_memset(p + n_s1 + n_s2, 0, 1);
	return (p);
}
