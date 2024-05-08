/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 00:58:14 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/09 07:26:06 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>
char	*ft_strrchr(const char *s, int c)
{
	int	i;

	
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (!((s[i] ^ c) & 255))
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*
int main(){
	printf("%s\n",ft_strrchr("aiueoaiueo",'e'));
	printf("%s\n",ft_strrchr("aiueoaiueo",'\0'));
	printf("%s\n",ft_strrchr("",'a'));
	printf("%s\n",ft_strrchr("",'\0'));
}
//*/
