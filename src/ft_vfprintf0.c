/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/21 13:45:16 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

int	get_cnt(void)
{
	return ((long long)ft_get_global("_vfp_cnt") & (int)-1);
}

void	set_cnt(int cnt)
{
	ft_set_global("_vfp_cnt", (void *)(long long)cnt);
}

void	del_cnt(void)
{
	ft_delone_global("_vfp_cnt", NULL);
}

int	add_cnt(int rhs)
{
	int	lhs;

	lhs = get_cnt();
	if (rhs < 0 || lhs > INT_MAX - rhs)
		set_cnt(EOF);
	else
		set_cnt(lhs + rhs);
	return (get_cnt());
}
