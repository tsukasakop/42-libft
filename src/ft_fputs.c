/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 05:01:31 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/13 05:01:31 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio.h"

int	fputs(const char *s, FILE *stream)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		if (cnt == INT_MAX)
			return (EOF);
		if (fputc(s[cnt], stream) == EOF)
			return (EOF);
		cnt++;
	}
	return (cnt);
}
