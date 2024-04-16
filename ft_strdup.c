/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 05:07:23 by tkondo            #+#    #+#             */
/*   Updated: 2024/01/25 09:44:43 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*dup;
	int		i;

	len = 0;
	while (src[len] != '\0')
		len++;
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = src[i];
		i++;
	}
	return (dup);
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
