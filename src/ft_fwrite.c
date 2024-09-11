/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:02:25 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/11 23:08:16 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

size_t	ft_fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < nitems)
	{
		while (j < size)
		{
			if (fputc(((unsigned char *)ptr)[size * i + j], stream) == EOF)
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
