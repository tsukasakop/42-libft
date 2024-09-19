/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/19 14:02:43 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"
#include "ft_stdio.h"
#include <limits.h>
#include <stdlib.h>

int	ft_fputc_f(int c, FILE *stream, int flag)
{
	if (flag && ft_fputc(c, stream) == EOF)
		return EOF;
	return (1);
}

int	ft_fputs_f(char *s, FILE *stream, int flag)
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

int	print_c(s_print *p, int do_print)
{
	if (ft_fputc_f((int)*(char *)(p->val), p->s, do_print) == EOF)
		return (EOF);
	return (1);
}

int	print_s(s_print *p, int do_print)
{
	return (ft_fputs_f(*(char **)(p->val), p->s, do_print));
}

int	print_nbr(s_print *p, unsigned int val, int do_print, char *base)
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

int	print_d(s_print *p, int do_print)
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

int	print_u(s_print *p, int do_print)
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

int	print_x(s_print *p, int do_print)
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

int	print_X(s_print *p, int do_print)
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

int	print_p(s_print *p, int do_print)
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

int	print_per(s_print *p, int do_print)
{
	if (ft_fputc_f('%', p->s, do_print) == EOF)
		return (EOF);
	return (1);
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

unsigned char	curc(s_print *p)
{
	return (*(p->cur));
}

unsigned char	step_cur(s_print *p)
{
	unsigned char	c;

	c = curc(p);
	(p->cur)++;
	return (c);
}

static void	*free_s_print(s_print *p)
{
	if (p->orig != NULL && p->cur != NULL)
		*(p->orig) = p->cur;
	free(p->val);
	free(p);
	return (NULL);
}

static void	read_flag(s_print *p)
{
	p->opt[0] = 0;
	while (1)
	{
		if (curc(p) == '#')
			p->opt[0] |= ALTER_FORM;
		else if (curc(p) == '0')
			p->opt[0] |= PAD_ZERO;
		else if (curc(p) == '-')
		{
			p->opt[0] |= ADJUST_LEFT;
			p->opt[0] &= ~PAD_ZERO;
		}
		else if (curc(p) == ' ')
			p->opt[0] |= BLANK_PNUM;
		else if (curc(p) == '+')
		{
			p->opt[0] |= SIGN_NUM;
			p->opt[0] &= ~BLANK_PNUM;
		}
		else
			return ;
		step_cur(p);
	}
}

static void	read_field(s_print *p)
{
	p->opt[1] = 0;
	if (!ft_isdigit(curc(p)))
		return ;
	while (ft_isdigit(curc(p)))
	{
		p->opt[1] = curc(p) - '0' + p->opt[1] * 10;
		step_cur(p);
	}
}

static void	read_prec(s_print *p)
{
	p->opt[2] = 0;
	if (curc(p) != '.')
		return ;
	p->opt[0] |= PRECITION;
	step_cur(p);
	while (ft_isdigit(curc(p)))
	{
		p->opt[2] = curc(p) - '0' + p->opt[2] * 10;
		step_cur(p);
	}
}

static int	set_mod(s_print *p, va_list ap)
{
	if (ft_strchr("cdixX", p->mod))
	{
		p->val = calloc(sizeof(int), 1);
		if (p->val == NULL)
			return (-1);
		*(int *)p->val = va_arg(ap, int);
	}
	else if (ft_strchr("sp", p->mod))
	{
		p->val = calloc(sizeof(void *), 1);
		if (p->val == NULL)
			return (-1);
		*(void **)p->val = va_arg(ap, void *);
	}
	else if (p->mod == '%')
		;
	return (0);
}

static int	get_mod_config(s_print *p, va_list ap)
{
	if (curc(p) == '\0' || ft_strchr("csdipxX%", curc(p)) == NULL)
		return (-1);
	p->mod = curc(p);
	step_cur(p);
	if (set_mod(p, ap) == -1)
		return (-1);
	if (p->mod == 'c')
		p->print_val = print_c;
	else if (p->mod == 's')
		p->print_val = print_s;
	else if (p->mod == 'd')
		p->print_val = print_d;
	else if (p->mod == 'i')
		p->print_val = print_d;
	else if (p->mod == 'x')
		p->print_val = print_x;
	else if (p->mod == 'X')
		p->print_val = print_X;
	else if (p->mod == 'p')
		p->print_val = print_p;
	else if (p->mod == '%')
		p->print_val = print_per;
	return (0);
}

int	put_pad(s_print *p, int is_before)
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
	if(vallen == EOF)
		return EOF;
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
		return free_s_print(p);
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
