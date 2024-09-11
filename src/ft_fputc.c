/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:19:13 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/11 11:22:36 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	ft_fputc(int c, FILE *stream)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	return (ft_fwrite((const char *)&uc, 1, 1, stream) * 2 - 1);
}
