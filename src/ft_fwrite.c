/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 01:02:25 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/11 11:25:38 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"
#include <unistd.h>

size_t	ft_fwrite(const void *ptr, size_t size, size_t n_items, FILE *stream)
{
	size_t	cnt;
	ssize_t	writen;
	int		fileno;

	fileno = ft_fileno(stream);
	cnt = 0;
	while (cnt < n_items)
	{
		writen = write(fileno, ptr + size * cnt, size);
		if (writen < 0 || (size_t)writen < size)
			break ;
		cnt++;
	}
	return (cnt);
}
