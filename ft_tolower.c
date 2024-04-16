/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:34:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/17 00:36:59 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	return (c + 32 * (c >= 'A' && c <= 'Z'));
}

/*
#include <stdio.h>
#include <ctype.h>
void	test(int i)
{
	printf("arg: \%d\n", i);
	printf("org: \%d\n", tolower(i));
	printf("slf: \%d\n\n", ft_tolower(i));
}
int	main(void)
{
	test('a');
	test('A');
	test('z');
	test('Z');
	test('-');
	test(' ');
	test('\n');
	test('~');
}
//*/
