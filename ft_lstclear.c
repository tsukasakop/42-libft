/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:27:25 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/09 05:09:51 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	if (lst == NULL)
		return ;
	while (*lst)
	{
		prev = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(prev, del);
	}
	*lst = NULL;
}
