/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:42:50 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/19 14:50:17 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

static int	print_d(s_print *p, int do_print)
{
	int	v;
	int	ret;
	int	_t;

	v = *(int *)p->val;
	if (v < 0)
		ret = ft_fputc_f('-', p->s, do_print);
	else if (p->opt[0] & SIGN_NUM)
		ret = ft_fputc_f('+', p->s, do_print);
	else if (p->opt[0] & BLANK_PNUM)
		ret = ft_fputc_f(' ', p->s, do_print);
	else
		ret = 0;
	if (ret == EOF)
		return (EOF);
	if (v < 0)
		v *= -1;
	_t = print_nbr(p, (unsigned int)v, do_print, "0123456789");
	if (_t == EOF || ret > INT_MAX - _t)
		return (EOF);
	return (ret + _t);
}

static int	print_u(s_print *p, int do_print)
{
	int				ret;
	int				_t;
	unsigned int	v;

	v = *(unsigned int *)p->val;
	if (p->opt[0] & SIGN_NUM)
		ret = ft_fputc_f('+', p->s, do_print);
	else if (p->opt[0] & BLANK_PNUM)
		ret = ft_fputc_f(' ', p->s, do_print);
	else
		ret = 0;
	if (ret == EOF)
		return (EOF);
	_t = print_nbr(p, v, do_print, "0123456789");
	if (_t == EOF || ret > INT_MAX - _t)
		return (EOF);
	return (ret + _t);
}

static int	print_x(s_print *p, int do_print)
{
	int				ret;
	int				_t;
	unsigned int	v;

	v = *(unsigned int *)p->val;
	if (p->opt[0] & ALTER_FORM)
		ret = ft_fputs_f("0x", p->s, do_print);
	else
		ret = 0;
	if (ret == EOF)
		return (EOF);
	_t = print_nbr(p, v, do_print, "0123456789abcdef");
	if (_t == EOF || ret > INT_MAX - _t)
		return (EOF);
	return (ret + _t);
}

static int	print_upper_x(s_print *p, int do_print)
{
	int				ret;
	int				_t;
	unsigned int	v;

	v = *(unsigned int *)p->val;
	if (p->opt[0] & ALTER_FORM)
		ret = ft_fputs_f("0X", p->s, do_print);
	else
		ret = 0;
	if (ret == EOF)
		return (EOF);
	_t = print_nbr(p, v, do_print, "0123456789ABCDEF");
	if (_t == EOF || ret > INT_MAX - _t)
		return (EOF);
	return (ret + _t);
}

static int	print_p(s_print *p, int do_print)
{
	int				ret;
	int				_t;
	unsigned int	v;

	v = *(unsigned int *)p->val;
	ret = ft_fputs_f("0x", p->s, do_print);
	if (ret == EOF)
		return (EOF);
	_t = print_nbr(p, v, do_print, "0123456789abcdef");
	if (_t == EOF || ret > INT_MAX - _t)
		return (EOF);
	return (ret + _t);
}
