/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/19 14:44:25 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"
#include "ft_stdio.h"
#include <limits.h>
#include <stdlib.h>

static int	put_pad(s_print *p, int is_before)
{
	char	pad_c;
	int		vallen;
	int		i;

	if ((is_before != 0) ^ ((p->opt[0] & ADJUST_LEFT) == 0))
		return (0);
	pad_c = ' ';
	if (p->opt[0] & PAD_ZERO && !(ft_strchr("diuxX", p->mod) != NULL
			&& p->opt[0] & PRECITION))
		pad_c = '0';
	vallen = p->print_val(p, 0);
	if (vallen == EOF)
		return (EOF);
	i = 0;
	while (i + vallen < p->opt[1])
	{
		if (ft_fputc(pad_c, p->s) == EOF)
			return (EOF);
		i++;
	}
	return (i);
}

static int	print_s_print(s_print *p)
{
	int	ret;
	int	_t;

	ret = put_pad(p, 1);
	if (ret == EOF)
		return (EOF);
	_t = p->print_val(p, 1);
	if (_t == -1 || ret > INT_MAX - _t)
		return (EOF);
	ret += _t;
	_t = put_pad(p, 0);
	if (_t == -1 || ret > INT_MAX - _t)
		return (EOF);
	return (ret + _t);
}

static s_print	*init_s_print(FILE *s, char **f, va_list ap)
{
	s_print	*p;

	p = ft_calloc(1, sizeof(s_print));
	if (p == NULL)
		return (NULL);
	p->s = s;
	p->orig = f;
	p->cur = *f;
	step_cur(p);
	read_flag(p);
	read_field(p);
	read_prec(p);
	if (get_mod_config(p, ap) == EOF)
		return (free_s_print(p));
	return (p);
}

static int	print_unit(FILE *s, char **f, va_list ap)
{
	s_print	*p;
	int		ret;

	if (**f != '%')
		return (print_raw(s, f));
	p = init_s_print(s, f, ap);
	if (p == NULL)
		return (-1);
	ret = print_s_print(p);
	free_s_print(p);
	return (ret);
}

int	ft_vfprintf(FILE *s, const char *format, va_list ap)
{
	int		cnt;
	int		_cnt;
	char	*f;

	cnt = 0;
	f = (char *)format;
	while (*f != '\0')
	{
		_cnt = print_unit(s, &f, ap);
		if (_cnt < 0 || cnt >= INT_MAX - _cnt)
			return (-1);
		cnt += _cnt;
	}
	return (cnt);
}
