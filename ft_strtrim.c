/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:52:43 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/27 17:01:04 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	strlen_pref(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

size_t	strlen_suf(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[len - 1 - i]) == NULL)
			break ;
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	n_pref;
	size_t	n_p;
	size_t	i;

	n_pref = strlen_pref(s1, set);
	n_p = ft_strlen(s1) - n_pref - strlen_suf(s1, set);
	n_p *= n_p > 0;
	p = malloc(n_p + 1);
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < n_p)
	{
		p[i] = s1[n_pref + i];
		i++;
	}
	p[n_p] = '\0';
	return (p);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s", "Hello, World");
	printf("%s", ft_strtrim("Hello, World", "World"));
}//*/
