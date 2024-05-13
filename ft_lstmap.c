/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:29:26 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/13 16:04:32 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*root;
	t_list	*new;
	t_list	*prev;
	t_list	*cur;

	cur = lst;
	root = NULL;
	while (cur)
	{
		new = ft_lstnew(f(cur->content));
		if (new == NULL)
		{
			ft_lstclear(&root, del);
			return (NULL);
		}
		if (root == NULL)
			root = new;
		else
			prev->next = new;
		prev = new;
		cur = cur->next;
	}
	return (root);
}
