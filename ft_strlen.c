/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:37:00 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/25 16:29:11 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"
size_t	ft_strlen(const char *s)

{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		cnt++;
		s++;
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
