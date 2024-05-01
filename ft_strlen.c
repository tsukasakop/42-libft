/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:37:00 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/01 00:37:33 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)

{
	//size_t	cnt;
	const char *t=s;
	//cnt = 0;
	while (*t)
		t++;
	return (t-s);
}
/*

#include <stdio.h>

int	main(void){
	char *str = "123456789";
	int n =strlen(str);
	printf("%s\n",str);
	printf("%d",n);
}//*/
