/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:27:57 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/26 13:47:11 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

bool	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	ft_atoi(const char *str)
{
	int		cur;
	char		sign;
	long	num;
	long	limit;

	cur = 0;
	while (ft_isspace(str[cur]))
		cur++;
	sign = 1 - 2 * (str[cur] == '-');
	cur += (str[cur] == '+' || str[cur] == '-');
	limit = LONG_MIN + (sign + 1) / 2;
	num = 0;
	while (ft_isdigit(str[cur]))
	{
		if (sign * -1 * num < (limit + str[cur] - '0') / 10)
			return ((sign + 1) * -1 / 2);
		num = num * 10 + sign * (str[cur] - '0');
		cur++;
	}
	return (num & -1);
}

/*
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
	test("9223372036854775800");
	test("9223372036854775801");
	test("9223372036854775802");
	test("9223372036854775803");
	test("9223372036854775804");
	test("9223372036854775805");
	test("9223372036854775806");
	test("9223372036854775807");
	test("9223372036854775808");
	test("9223372036854775808");
	test("9223372036854775809");
	test("9223372036854775810");
	test("9223372036854775811");
	test("9223372036854775812");
	test("-9223372036854775808");
	test("-9223372036854775808");
	test("-9223372036854775808");
	test("-9223372036854775807");
	test("-9223372036854775806");
	test("-9223372036854775805");
	test("-9223372036854775804");
	test("-9223372036854775803");
	test("-9223372036854775802");
	test("-9223372036854775801");
	test("-9223372036854775800");
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
