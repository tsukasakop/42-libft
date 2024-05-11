/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 13:33:35 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/11 17:45:07 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdbool.h>
#include <stdlib.h>

static bool	cnt_word(char const *begin, char const *end, void *p)
{
	(void)begin;
	(void)end;
	(*((int *)p))++;
	return (true);
}

static bool	append_word(char const *begin, char const *end, void *p)
{
	char	***addr;

	addr = (char ***)p;
	**addr = ft_substr(begin, 0, end - begin);
	if (**addr == NULL)
		return (false);
	(*addr)++;
	return (true);
}

static bool	split_word_iter(char const *s, char c, void *p,
		bool (*f)(char const *, char const *, void *))
{
	char const	*cur_begin;
	char const	*cur_end;

	cur_begin = s;
	while (true)
	{
		while (*cur_begin && *cur_begin == c)
			cur_begin++;
		if (*cur_begin == '\0')
			return (true);
		cur_end = ft_strchr(cur_begin, c);
		if (cur_end == NULL)
			cur_end = cur_begin + ft_strlen(cur_begin);
		if (!f(cur_begin, cur_end, p))
			return (false);
		cur_begin = cur_end;
	}
}

static void	free_all(char ***p)
{
	char	***begin;

	begin = p;
	while (**p){
		free(**p);
		(*p)++;
	}
	free(*begin);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		cnt;
	char	**_p;

	cnt = 0;
	split_word_iter(s, c, &cnt, cnt_word);
	p = ft_calloc(sizeof(char *), cnt + 1);
	_p = p;
	if (p != NULL && !split_word_iter(s, c, &_p, append_word))
		free_all(&p);
	return (p);
}
