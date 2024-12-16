/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:54:46 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/11 15:55:41 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_global.h"
#include "ft_string.h"

void	ch_test(void)
{
	char	*p;

	p = ft_strdup("miyumiyu");
	ft_set_global("mfunakos", p);
}

int	main(void)
{
	char	*p;

	p = ft_strdup("kon.d.tsukasa");
	ft_set_global("tkondo", p);
	ch_test();
	ft_mmfree();
}
