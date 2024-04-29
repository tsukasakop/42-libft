/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:29:26 by tkondo            #+#    #+#             */
/*   Updated: 2024/04/29 19:47:40 by tkondo           ###   ########.fr       */
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
/*

#include <stdio.h>
#include <string.h>
#include <ctype.h>
static void *str_toupper(void *p)
{
    char *str = strdup((char *)p);
    char *tmp = str;
    while (*tmp)
    {
        *tmp = toupper(*tmp);
        tmp++;
    }
    return (str);
}

static void *str_tolower(void *p)
{
    char *str = strdup((char *)p);
    char *tmp = str;
    while (*tmp)
    {
        *tmp = tolower(*tmp);
        tmp++;
    }
    return (str);
}
int main(){
    t_list  *lst = ft_lstnew(strdup("Hello"));
    ft_lstadd_back(&lst, ft_lstnew(strdup(" World")));
    ft_lstadd_back(&lst, ft_lstnew(strdup(" 42")));
    ft_lstadd_back(&lst, ft_lstnew(strdup(" Tokyo!")));
    ft_lstadd_back(&lst, ft_lstnew(strdup("")));

    // toupper
    t_list *newlst = ft_lstmap(lst, str_toupper, free);
    // tolower
    newlst = ft_lstmap(lst, str_tolower, free);
	while(newlst)
{
printf("%s\n", newlst->content);
newlst=newlst->next;}
}//*/
