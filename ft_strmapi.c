/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:14:02 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/27 18:14:35 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t i;
	i = 0;
	char *p = malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (NULL);
	while (s[i])
	{
		p[i] = f(i, s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
