/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:49:42 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/27 18:09:15 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
size_t	digit(int n)
{
	if (n / 10 == 0)
		return (1);
	return (digit(n / 10) + 1);
}

void	set_digit(int n, char *p, size_t cur)
{
	p[cur] = n % 10 * ((n > 0) * 2 - 1) + '0';
	if (n / 10)
		set_digit(n / 10, p, cur - 1);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*p;

	len = digit(n) + (n < 0);
	p = malloc(len + 1);
	p[len] = '\0';
	if (p == NULL)
		return (NULL);
	if (n < 0)
		p[0] = '-';
	set_digit(n, p, len - 1);
	return (p);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_itoa(-123));
}//*/
