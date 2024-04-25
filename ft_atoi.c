/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:27:57 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/25 19:16:16 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include <stdio.h>
bool	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;
	int	cur;

	num = 0;
	cur = 0;
	while (ft_isspace(str[cur]))
		cur++;
	sign = 1 - 2 * (str[cur] == '-');
	if (str[cur] == '+' || str[cur] == '-')
		cur++;
	while (ft_isdigit(str[cur]))
	{
		num = num * 10 + sign * (str[cur] - '0');
		cur++;
	}
//	printf("| %d <- ",num);
	return (num);
}

//*
#include <stdio.h>
#include <stdlib.h>

void	test(char *str)
{
	if (!*str)
		return ;
	printf("orig:\t%s\n", str);
	printf("std:\t%d\n", atoi(str));
	printf("self:\t%d\n", ft_atoi(str));
	printf("\n");
}
int	main(void)
{
	test("0");
	test("-1");
	test("1");
	test("2147483647");
	test("-2147483648");
	test("2147483648");
	test("-2147483649");
	test(" 42");
	test(" +42");
	test(" -42");
	test(" \r\t\f\v\n42");
	test("9223372036854775808");
	test("-9223372036854775809");
	test("18446744073709551616");
	test("18446744073709551614");
	test("-+122");
	test("");
	test("");
	test("");
	test("");
	test("");
	test("");
}
//*/
