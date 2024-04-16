/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 10:27:57 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/16 11:03:51 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
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
	while (str[cur] >= '0' && str[cur] <= '9')
	{
		num = num * 10 + str[cur] - '0';
		cur++;
	}
	return (sign * num);
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
	test("");
	test("");
	test("");
	test("");
	test("");
	test("");
	test("");
	test("");
	test("");
	test("");
	test("");
}
//*/
