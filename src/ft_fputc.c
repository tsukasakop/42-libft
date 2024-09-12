/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:19:13 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/12 20:32:20 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# include "ft_stdio.h"
# include "ft_stdlib.h"

int	ft_fputc(int c, FILE *stream)
{
	size_t	bfsize;

	bfsize = 4096;
	if (stream->_bf._base == NULL)
	{
		stream->_bf._base = (unsigned char *)ft_calloc(bfsize, 1);
		stream->_bf._size = bfsize;
		if (stream->_bf._base == NULL)
			return (EOF);
		stream->_p = stream->_bf._base;
	}
	if (stream->_w + stream->_bf._size == 0 && ft_fflush(stream) == EOF)
		return (EOF);
	*stream->_p = (unsigned char)c;
	stream->_p++;
	stream->_w--;
	return (c);
}

#elif __linux__
# include "ft_stdio.h"
# include <unistd.h>

int	ft_fputc(int c, FILE *stream)
{
	if (write(ft_fileno(stream), &c, 1) == -1)
		return (EOF);
	return (c);
}

#endif
