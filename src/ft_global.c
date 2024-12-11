/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_global.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:44:16 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/11 15:54:54 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_global.h"

t_htbl	ft_get_globals(void)
{
	static t_htbl	dict;

	if (!dict)
		dict = htnew();
	return (dict);
}

int	ft_set_global(const char *key, void *val)
{
	t_htbl	dict;

	dict = ft_get_globals();
	if (!dict)
		return (0);
	return (!!htadd(dict, key, val));
}

void	*ft_get_global(const char *key)
{
	t_htbl	dict;

	dict = ft_get_globals();
	if (!dict)
		return (0);
	return (htget(dict, key));
}
