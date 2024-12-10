/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_FILE.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:59:44 by tkondo            #+#    #+#             */
/*   Updated: 2024/10/26 17:03:33 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
typedef struct test
{
	int i;
	char *c;
	char ar[2];
} test;

test	get_stdin_stream()
{
	test t = {.i=10, .c="aiueo"};
	t.ar[0] = 4;
	t.ar[1] = 7;
	return t;
}

int main()
{
	test t = get_stdin_stream();
	printf("i=%d, c=%s, ar=[%d, %d]", t.i, t.c, t.ar[0], t.ar[1]);
}
