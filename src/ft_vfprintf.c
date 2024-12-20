/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/20 19:27:51 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"
#include "ft_stdio.h"
#include "ft_string.h"
#include "ft_memory.h"
#include "ft_global.h"
#include <limits.h>
#include <stdlib.h>

static int get_cnt()
{
	return (long long)ft_get_global("_vfp_cnt") & (int)-1;
}

void	set_cnt(int cnt)
{
	ft_set_global("_vfp_cnt", (void *)(long long)cnt);
}

void	del_cnt()
{
	ft_delone_global("_vfp_cnt", NULL);
}

static int add_cnt(int rhs)
{
	int lhs;
	lhs = get_cnt();
	if(rhs < 0 || lhs > INT_MAX - rhs)
		set_cnt(EOF);
	else
		set_cnt(lhs + rhs);
	return get_cnt();
}

void	ft_fputc_wrapper(int c, FILE *stream)
{
	if (get_cnt() == EOF)
		return;
	if(ft_fputc(c, stream) == EOF)
		set_cnt(EOF);
	else
		add_cnt(1);
}

void	read_flag(const char **f, t_format *fmt)
{
	while (1)
	{
		if (**f == '#')
			fmt->s_flag.num = 1;
		else if (**f == '0')
			fmt->s_flag.zero = 1;
		else if (**f == '-')
			fmt->s_flag.minus = 1;
		else if (**f == ' ')
			fmt->s_flag.space = 1;
		else if (**f == '+')
			fmt->s_flag.plus = 1;
		else
			return ;
		++*f;
	}
}

int	read_nbr(const char **f)
{
	int n;
	n = 0;
	while (ft_isdigit(**f))
	{
		if(n > (INT_MAX - **f + '0') / 10)
			return EOF;
		n = **f - '0' + n * 10;
		++*f;
	}
	return n;
}

int	read_arg(const char **f, t_format *p, va_list ap)
{
	p->mod = **f;
	++*f;
	if (ft_strchr("cdiuxX", p->mod))
		p->u_val.nbr = va_arg(ap, int);
	else if (ft_strchr("sp", p->mod))
		p->u_val.ptr = va_arg(ap, void *);
	else if (p->mod == '%')
		;
	else
		return 0;
	return (1);
}

void read_raw(t_format *fmt, const char **f)
{
		size_t i;

		fmt->mod = 'R';
		i=0;
		while((*f)[i] && (*f)[i] != '%')
			++i;
		fmt->u_val.ptr = (void *)ft_strndup(*f, i);
		ft_g_mmadd(fmt->u_val.ptr);
		*f += i;
}

t_format	*read_fmt(const char **f, va_list ap)
{
	t_format	*fmt;

	fmt = ft_g_mmcalloc(1, sizeof(t_format));
	if (fmt == NULL)
		return (NULL);
	if (**f != '%')
		read_raw(fmt, f);
	else
	{
		++*f;
		read_flag(f, fmt);
		fmt->field = read_nbr(f);
		if(**f == '.')
		{
			++*f;
			fmt->s_flag.period = 1;
			fmt->prec = read_nbr(f);
		}
		read_arg(f, fmt, ap);
	}
	return (fmt);
}

char get_sign(t_format *f)
{
	if(f->u_val.nbr < 0)	return '-';
	if(f->s_flag.plus) return '+';
	if(f->s_flag.space) return ' ';
	return '\0';
}

void set_f_width(t_print *p, t_format *f)
{
	int f_width;
	f_width = f->field - p->inner_len - p-> zero_len;
	if(p->sign)
		f_width--;
	if(p->prefix)
		f_width -= ft_strlen(p->prefix);
	if(f_width < 0)
		return;
	if(f->s_flag.minus)
		p->r_ws_len = f_width; 
	else if(f->s_flag.zero && !f->s_flag.period)
		p->zero_len += f_width;
	else
		p->l_ws_len = f_width;
}

void set_prec(t_print *p, t_format *f)
{
	int prec;prec = f->prec - p->inner_len;
	if(prec<0)
		return;
	if(f->s_flag.period)
		p->zero_len = prec;
	set_f_width(p, f);
}

char *ft_ui64toa_base(uint64_t i, const char* base, unsigned char base_len)
{
	char	buf[65];
	int		cur;

	buf[64] = '\0';
	cur = 64;
	if (!i)
	{
		cur--;
		buf[cur] = base[0];
	}
	while (i)
	{
		cur--;
		buf[cur] = base[i % base_len];
		i /= base_len;
	}
	return ft_strdup(buf + cur);
}

void	init_print_percent(t_format *f, t_print *p)
{
	p->p = (const unsigned char *)"%";
	p->inner_len = 1;
	(void)f;
}

void	init_print_s(t_format *f, t_print *p)
{
	f->s_flag.zero = 0;
	if(!f->u_val.ptr && !(f->s_flag.period && f->prec < 6))
		f->u_val.ptr = "(null)";
	if(!f->u_val.ptr)
		p->inner_len = 0;
	else
		p->inner_len = ft_strnlen(f->u_val.ptr, (size_t)INT_MAX);
	if(f->s_flag.period && f->prec < p->inner_len)
		p->inner_len = f->prec;
	p->p = f->u_val.ptr;
	set_f_width(p, f);
}

void	init_print_c(t_format *f, t_print *p)
{
	f->s_flag.zero = 0;
	p->p = (const unsigned char *)&f->u_val.nbr;
	p->inner_len = 1;
	set_f_width(p, f);
}

void	init_print_d(t_format *f, t_print *p)
{
	p->sign = get_sign(f);
	if(p->sign == '-')
		f->u_val.nbr *= -1;
	p->p = (const unsigned char *)ft_ui64toa_base((uint64_t)(uint32_t)f->u_val.nbr, "0123456789", 10);
	ft_g_mmadd((void *)p->p);
	p->inner_len = ft_strnlen((const char *)p->p, (size_t)INT_MAX);
	if(!f->u_val.nbr && f->s_flag.period && !f->prec)
		p->inner_len = 0;
	set_prec(p, f);
	set_f_width(p, f);
}

void init_print_u(t_format *f, t_print *p)
{
	p->p = (const unsigned char *)ft_ui64toa_base((uint64_t)(uint32_t)f->u_val.nbr, "0123456789", 10);
	ft_g_mmadd((void *)p->p);
	p->inner_len = ft_strnlen((const char *)p->p, (size_t)INT_MAX);
	if(!f->u_val.nbr && f->s_flag.period && !f->prec)
		p->inner_len = 0;
	set_prec(p, f);
	set_f_width(p, f);
}

void init_print_x(t_format *f, t_print *p)
{
	if(f->s_flag.num)
		p->prefix = "0x";
	p->p = (const unsigned char *)ft_ui64toa_base((uint64_t)(uint32_t)f->u_val.nbr, "0123456789abcdef", 16);
	ft_g_mmadd((void *)p->p);
	p->inner_len = ft_strnlen((const char *)p->p, (size_t)INT_MAX);
	if(!f->u_val.nbr && f->s_flag.period && !f->prec)
		p->inner_len = 0;
	set_prec(p, f);
	set_f_width(p, f);
}

void init_print_X(t_format *f, t_print *p)
{
	if(f->s_flag.num)
		p->prefix = "0X";
	p->p = (const unsigned char *)ft_ui64toa_base((uint64_t)(uint32_t)f->u_val.nbr, "0123456789ABCDEF", 16);
	ft_g_mmadd((void *)p->p);
	p->inner_len = ft_strnlen((const char *)p->p, (size_t)INT_MAX);
	if(!f->u_val.nbr && f->s_flag.period && !f->prec)
		p->inner_len = 0;
	set_prec(p, f);
	set_f_width(p, f);
}

void init_print_p(t_format *f, t_print *p)
{
	if(!f->u_val.ptr)
		p->p = (const unsigned char *)"(nil)";
	else
	{
		p->prefix = "0x";
		p->p = (const unsigned char *)ft_ui64toa_base((uint64_t)f->u_val.nbr, "0123456789abcdef", 16);
		ft_g_mmadd((void *)p->p);
	}
	p->inner_len = ft_strnlen((const char *)p->p, (size_t)INT_MAX);
	set_prec(p, f);
	set_f_width(p, f);
}

t_print	*norm_fmt(t_format *f)
{
	t_print	*p;
	p = (t_print *)ft_g_mmcalloc(sizeof(t_print), 1);
	if(!p)
		return NULL;
	if(f->mod == 'R')
		init_print_s(f, p);
	if(f->mod == '%')
		init_print_percent(f, p);
	if(f->mod == 'c')
		init_print_c(f, p);
	if(f->mod == 's')
		init_print_s(f, p);
	if(f->mod == 'd')
		init_print_d(f, p);
	if(f->mod == 'i')
		init_print_d(f, p);
	if(f->mod == 'u')
		init_print_u(f, p);
	if(f->mod == 'x')
		init_print_x(f, p);
	if(f->mod == 'X')
		init_print_X(f, p);
	if(f->mod == 'p')
		init_print_p(f, p);
	return p;
}

void	print_l_ws(FILE *s, t_print *p)
{
	int cnt;cnt =0;
	while(cnt++ < p->l_ws_len)
		ft_fputc_wrapper(' ', s);
}
void	print_sign(FILE *s, t_print *p)
{
	if(p->sign)
		ft_fputc_wrapper(p->sign, s);
}
void	print_pref(FILE *s, t_print *p)
{
	int cnt;cnt = 0;
	if(p->prefix)
	{
		while(p->prefix[cnt])
			ft_fputc_wrapper(p->prefix[cnt++], s);
	}
}
void	print_zero(FILE *s, t_print *p)
{
	int cnt;cnt =0;
	while(cnt++ < p->zero_len)
		ft_fputc_wrapper('0', s);
}

void	print_data(FILE *s, t_print *p)
{
	int cnt;cnt=0;

	char c;
	while(cnt < p->inner_len)
	{
		if(!p->base)
			c = p->p[cnt];
		else
			c = p->base[p->p[cnt]];
		ft_fputc_wrapper(c, s);
		if(get_cnt() == EOF)
			return ;
		cnt++;
	}
}

void	print_r_ws(FILE *s, t_print *p)
{
	int cnt;cnt =0;
	while(cnt++ < p->r_ws_len)
		ft_fputc_wrapper(' ', s);
}

void print_unit(FILE *s, t_print *p)
{
	print_l_ws(s, p);
	print_sign(s, p);
	print_pref(s, p);
	print_zero(s, p);
	print_data(s, p);
	print_r_ws(s, p);
}

void	print_by_unit(FILE *s, const char **f, va_list ap)
{
	t_print	*p;
	t_format *fmt;

	fmt = read_fmt(f, ap);
	p = norm_fmt(fmt);
	if(!p)
		set_cnt(EOF);
	else
		print_unit(s, p);
	ft_g_mmfree();
}

int	ft_vfprintf(FILE *s, const char *format, va_list ap)
{
	int cnt;

	set_cnt(0);
	while (*format != '\0')
	{
		print_by_unit(s, &format, ap);
		if(get_cnt() == EOF)
			break;
	}
	cnt = get_cnt();
	del_cnt();
	return (cnt);
}
