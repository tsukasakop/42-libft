/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 20:05:24 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/12 21:20:26 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef __APPLE__
# include "ft_stdio.h"
# include <unistd.h>

int	ft_fflush(FILE *stream)
{
	size_t	nbyte;
	size_t	ret;

	if (stream->_p == NULL)
		return (0);
	nbyte = (size_t)(stream->_w * ((stream->_w > 0) * 2 - 1));
	ret = write(ft_fileno(stream), stream->_bf._base, nbyte);
	if (ret != nbyte)
		return (EOF);
	stream->_p = stream->_bf._base;
	stream->_w = 0;
	return (0);
}

#elif __linux__
# include <stdio.h>

int	ft_fflush(FILE *stream)
{
	(void)stream;
	return EOF
}
#endif
