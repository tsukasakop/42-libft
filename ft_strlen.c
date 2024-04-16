/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:37:00 by tkondo            #+#    #+#             */
/*   Updated: 2024/01/16 19:28:44 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		cnt++;
		str++;
	}
	return (cnt);
}
/*
#include <stdio.h>
int main(){
	char *str = "123456789";
	int n =ft_strlen(str);
	printf("%s\n",str);
	printf("%d",n);
}
*/
