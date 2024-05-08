/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:50:26 by tkondo            #+#    #+#             */
/*   Updated: 2024/05/09 05:17:13 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*word_dup(char *start, int length)
{
	char	*word;
	int		i;

	word = malloc(length + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		word[i] = start[i];
		i++;
	}
	word[length] = '\0';
	return (word);
}

int	cnt_words(char *str, char c)
{
	char	*s;
	int		cnt;

	cnt = 0;
	s = str;
	while (*s)
	{
		if (*s != c && (s == str || *(s - 1) == c))
			cnt += 1;
		s++;
	}
	return (cnt);
}

char	**set_words(char *str, char c, char **res)
{
	char	*start;
	char	*s;
	int		index;

	s = str;
	index = 0;
	while (*s)
	{
		if (*s != c && (s == str || *(s - 1) == c))
			start = s;
		if (*s != c && (!*(s + 1) || *(s + 1) == c))
		{
			res[index] = word_dup(start, s - start + 1);
			if (res[index] == NULL)
				return (NULL);
			index++;
		}
		s++;
	}
	res[index] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**words;

	if (s == NULL)
		return (NULL);
	count = cnt_words((char *)s, c);
	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);
	if (set_words((char *)s, c, words) == NULL)
	{
		while (*words)
		{
			free(*words);
			words++;
		}
		free(words);
		return (NULL);
	}
	return (words);
}
