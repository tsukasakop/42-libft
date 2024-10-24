/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_0.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:40:52 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/19 15:02:41 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_stdio.h"

static int	ft_fputc_f(int c, FILE *stream, int flag)
{
	if (flag && ft_fputc(c, stream) == EOF)
		return (EOF);
	return (1);
}

static int	ft_fputs_f(char *s, FILE *stream, int flag)
{
	int	cnt;

	cnt = 0;
	while (s[cnt] != '\0')
	{
		if (ft_fputc_f(s[cnt], stream, flag) == EOF || cnt == INT_MAX)
			return (EOF);
		cnt++;
	}
	return (cnt);
}

static int	print_raw(FILE *s, char **f)
{
	int	cnt;

	cnt = 0;
	while (ft_strchr("%\0", **f) == NULL)
	{
		if (ft_fputc(*(*f)++, s) == EOF)
			return (-1);
		if (++cnt == INT_MAX)
			return (-1);
	}
	return (cnt);
}

static int	print_c(s_print *p, int do_print)
{
	if (ft_fputc_f((int)*(char *)(p->val), p->s, do_print) == EOF)
		return (EOF);
	return (1);
}

static int	print_s(s_print *p, int do_print)
{
	return (ft_fputs_f(*(char **)(p->val), p->s, do_print));
}

static int	print_nbr(s_print *p, unsigned int val, int do_print, char *base)
{
	size_t	base_len;
	char	str[33];
	int		cur;

	str[32] = '\0';
	cur = 32;
	base_len = (int)ft_strlen(base);
	if (val == 0)
	{
		cur--;
		str[cur] = base[0];
	}
	while (p->opt[2] > 32 - cur || val != 0)
	{
		cur--;
		str[cur] = base[val % base_len];
		val /= base_len;
	}
	return (ft_fputs_f(str + cur, p->s, do_print));
}
