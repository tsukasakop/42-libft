/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:34:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/17 00:39:28 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	return (c - 32 * (c >= 'a' && c <= 'z'));
}

/*
#include <stdio.h>
#include <ctype.h>
void	test(int i)
{
	printf("arg: \%d\n", i);
	printf("org: \%d\n", toupper(i));
	printf("slf: \%d\n\n", ft_toupper(i));
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
