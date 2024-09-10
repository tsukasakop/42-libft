/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fileno.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 15:50:13 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/11 01:43:41 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#ifdef __APPLE__

int	ft_fileno(FILE *stream)
{
	return (stream->_file);
}
#elif __linux__

int	ft_fileno(FILE *stream)
{
	return (stream->_fileno);
}
#endif
