/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 05:07:23 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/28 21:24:12 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*p;

	len = ft_strlen(s1);
	p = malloc(len + 1);
	if (p == NULL)
		return (NULL);
	ft_memcpy(p, s1, len + 1);
	return (p);
}

/*
#include <stdio.h>

int	main(void) {
	char *original = "Hello, world!";
	char *duplicate = ft_strdup(original);
	if (duplicate != NULL) {
		printf("Duplicate: %s\n", duplicate);
		free(duplicate);     }
	return (0);
}
//*/
