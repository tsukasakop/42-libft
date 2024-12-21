/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/21 21:23:13 by tkondo           ###   ########.fr       */
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

int can_add_to_cnt(int c)
{
	int cnt;

	cnt = get_cnt();
	return (cnt < INT_MAX && c >= 0 && cnt < INT_MAX - c);
}
	
int	add_cnt(int rhs)
{
	if(!can_add_to_cnt(rhs))
		set_cnt(EOF);
	else
		set_cnt(get_cnt() + rhs);
	return (get_cnt());
}
