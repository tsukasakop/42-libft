/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 03:20:31 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/13 03:31:54 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		n;

	va_start(args, format);
	n = ft_vfprintf(stdout, format, args);
	va_end(args);
	return (n);
}
