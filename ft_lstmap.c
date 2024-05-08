/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:29:26 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/09 05:02:52 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*leaf;

	if (lst == NULL)
		return (NULL);
	node = ft_lstnew(f(lst->content));
	if (node == NULL)
		return (NULL);
	if (lst->next == NULL)
		return (node);
	leaf = ft_lstmap(lst->next, f, del);
	if (leaf == NULL)
	{
		ft_lstdelone(node, del);
		return (NULL);
	}
	ft_lstadd_front(&leaf, node);
	return (leaf);
}
