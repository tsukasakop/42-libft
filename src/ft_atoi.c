/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:27:57 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/11 00:50:57 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "ft_ctype.h"

int	ft_atoi(const char *str)
{
	char	sign;
	long	num;
	long	limit;

	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = 1 - 2 * (*str == '-');
	str += (*str == '+' || *str == '-');
	limit = LONG_MIN + (sign + 1) / 2;
	num = 0;
	while (ft_isdigit(*str))
	{
		if (sign * -1 * num < (limit + *str - '0') / 10)
			return ((sign + 1) * -1 / 2);
		num = num * 10 + sign * (*str - '0');
		str++;
	}
	return (num & -1);
}
