/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/17 14:20:24 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"
#include "ft_stdio.h"
#include "ft_memory.h"
#include <limits.h>
#include <stdlib.h>

static int *get_cnt_p()
{
	static int cnt;
	return &cnt;
}

static int get_cnt()
{
	return *get_cnt_p();
}

void	set_cnt(int cnt)
{
	*get_cnt_p() = cnt;
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

/*
void	ft_fputs_f(char *s, FILE *stream, int n, int flag)
{
	int	cnt;
	(void)n;
	cnt = 0;
	while (s[cnt] != '\0')
	{
		ft_fputc_f(s[cnt], stream, flag);
		cnt++;
	}
}

void print_c(t_format *p, int do_print)
{
	ft_fputc_f((int)*(char *)(p->val), p->s, do_print);
}

void print_s(t_format *p, int do_print)
{
	int cnt;
	if (!*(char **)(p->val))
		*(char **)(p->val) = "(null)";
	if(p->opt[0] & PRECITION)
	{
		cnt = 0;
		while(cnt < p->opt[2] && (*(char **)(p->val))[cnt])
		{
			ft_fputc_f((*(char **)(p->val))[cnt], p->s, do_print);
			cnt++;
		}
		return;
	}
	ft_fputs_f(*(char **)(p->val), p->s, p->opt[2], do_print);
}

void	print_nbr(t_format *p, unsigned int val, int do_print, char *base)
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
	ft_fputs_f(str + cur, p->s, p->opt[2], do_print);
}

void	print_d(t_format *p, int do_print)
{
	int	v;

	v = *(int *)p->val;
	if (v < 0)
		ft_fputc_f('-', p->s, do_print);
	else if (p->opt[0] & SIGN_NUM)
		ft_fputc_f('+', p->s, do_print);
	else if (p->opt[0] & BLANK_PNUM)
		ft_fputc_f(' ', p->s, do_print);
	//print_sign(p);
	if(v < 0)	
		v *= -1;
	print_nbr(p, (unsigned int)v, do_print, "0123456789");
}

void	print_u(t_format *p, int do_print)
{
	unsigned int	v;

	v = *(unsigned int *)p->val;
	if (p->opt[0] & SIGN_NUM)
		ft_fputc_f('+', p->s, do_print);
	else if (p->opt[0] & BLANK_PNUM)
		ft_fputc_f(' ', p->s, do_print);
	print_nbr(p, v, do_print, "0123456789");
}

void	print_x(t_format *p, int do_print)
{
	unsigned int	v;

	v = *(unsigned int *)p->val;
	if (p->opt[0] & ALTER_FORM)
		ft_fputs_f("0x", p->s, p->opt[2], do_print);
	print_nbr(p, v, do_print, "0123456789abcdef");
}

void	print_X(t_format *p, int do_print)
{
	unsigned int	v;

	v = *(unsigned int *)p->val;
	if (p->opt[0] & ALTER_FORM)
	{
		ft_fputs_f("0X", p->s, p->opt[2], do_print);
		p->opt[2] -= 2;
	}
	print_nbr(p, v, do_print, "0123456789ABCDEF");
}

void	print_p(t_format *p, int do_print)
{
	unsigned int	v;

	v = *(unsigned int *)p->val;
	if(!v)
	{
		(ft_fputs_f("(nil)", p->s, 5, do_print));
		return;
	}
	ft_fputs_f("0x", p->s, p->opt[2], do_print);
	p->opt[2] -= 2;
	print_nbr(p, v, do_print, "0123456789abcdef");
}

void	print_per(t_format *p, int do_print)
{
	ft_fputc_f('%', p->s, do_print);
}

int	print_raw(FILE *s, char **f)
{
	int	cnt;

	cnt = 0;
	while (ft_strchr("%\0", **f) == NULL)
	{
		ft_fputc(*(*f)++, s);
	}
	return (cnt);
}
*/
unsigned char	curc(t_format *p)
{
	return (*(p->cur));
}

unsigned char	step_cur(t_format *p)
{
	unsigned char	c;

	c = curc(p);
	(p->cur)++;
	return (c);
}

void	*free_s_print(t_format *p)
{
	if (p->orig != NULL && p->cur != NULL)
		*(p->orig) = p->cur;
	free(p->val);
	free(p);
	return (NULL);
}

void	read_flag(t_format *p)
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

void	read_field(t_format *p)
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

void	read_prec(t_format *p)
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

int	set_mod(t_format *p, va_list ap)
{
	p->mod = curc(p);
	step_cur(p);
	if (ft_strchr("cdiuxX", p->mod))
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

t_format	*load_fmt(const char **f, va_list ap)
{
	(void)ap;
	t_format	*p;

	p = ft_calloc(1, sizeof(t_format));
	if (p == NULL)
		return (NULL);
	if (**f != '%')
	{
		p->mod = 'R';
		p->cur = *f;
		p->orig = f;
		p->begin = *f;
		while(curc(p) && curc(p) != '%')
			step_cur(p);
		return p;
	}

		p->cur = *f;
	p->orig = f;
	p->begin = *f;
	step_cur(p);
	read_flag(p);
	read_field(p);
	read_prec(p);
	if (set_mod(p, ap) == -1)
		return (NULL);
	return (p);
}

t_print *init_print_raw(t_format *f)
{
	t_print	*p;
	p = (t_print *)ft_mmcalloc(sizeof(t_print), 1);
	if(!p)
		return NULL;
	while(f->begin[p->inner_len] && f->begin[p->inner_len] != '%')
	{
		if(p->inner_len > INT_MAX - 1)
			return NULL;
		p->inner_len++;
	}
	p->p = (const unsigned char *)f->begin;	
	return p;
}

char get_sign(t_format *f)
{
	int v;v = *(int *)f->val;

	if(v<0)	return '-';
	if(f->opt[0] & SIGN_NUM) return '+';
	if(f->opt[0] & BLANK_PNUM) return ' ';
	return '\0';
}

void set_f_width(t_print *p, t_format *f)
{
	int f_width;
	f_width = f->opt[1] - p->inner_len - p-> zero_len;
	if(p->sign)
		f_width--;
	if(p->prefix)
		f_width -= ft_strlen(p->prefix);
	if(f_width < 0)
		return;
	if(f->opt[0] & ADJUST_LEFT)
		p->r_ws_len = f_width; 
	else if(f->opt[0] & PAD_ZERO && ~f->opt[0] & PRECITION)
		p->zero_len += f_width;
	else
		p->l_ws_len = f_width;
}

void set_f_width_nbr(t_print *p, t_format *f)
{
	int f_width;
	f_width = f->opt[1] - p->inner_len - p-> zero_len;
	if(p->sign)
		f_width--;
	if(p->prefix)
		f_width -= ft_strlen(p->prefix);
	if(f_width < 0)
		return;
	if(f->opt[0] & ADJUST_LEFT)
		p->r_ws_len = f_width; 
	else if(f->opt[0] & PAD_ZERO && ~f->opt[0] & PRECITION)
		p->zero_len += f_width;
	else
		p->l_ws_len = f_width;
}

void set_prec(t_print *p, t_format *f)
{
	int prec;prec = f->opt[2] - p->inner_len;
	if(prec<0)
		return;
	if(f->opt[0] & PRECITION)
		p->zero_len = prec;
	set_f_width(p, f);
}

t_print *init_print_percent(t_format *f)
{
	t_print	*p;
	p = (t_print *)ft_mmcalloc(sizeof(t_print), 1);
	if(!p)
		return NULL;
	p->inner_len = 1;
	p->p = (const unsigned char *)f->begin;	
//	set_f_width(p, f);
	return p;
}

t_print *init_print_s(t_format *f)
{
	t_print	*p;
	p = (t_print *)ft_mmcalloc(sizeof(t_print), 1);
	if(!p)
		return NULL;
	if(*(char **)f->val == NULL)
	{
		*(char **)f->val = "(null)";
		if(f->opt[2] < 6)
			p->inner_len = 0;
		else
			p->inner_len = 6;
	}
	else
	{
		size_t n; n = ft_strlen(*(char **)f->val);
		if(n > INT_MAX)
			p->inner_len = INT_MAX;
		else
			p->inner_len = (int)n;
	}
	if(f->opt[0] & PRECITION && f->opt[2] < p->inner_len)
		p->inner_len = f->opt[2];
	p->p = *(const unsigned char **)f->val;
	f->opt[0] &= ~PAD_ZERO;
	set_f_width(p, f);
	return p;
}

t_print *init_print_c(t_format *f)
{
	t_print	*p;
	p = (t_print *)ft_mmcalloc(sizeof(t_print), 1);
	if(!p)
		return NULL;
	p->inner_len = 1;
	p->p = (const unsigned char *)f->val;
	f->opt[0] &= ~PAD_ZERO;
	set_f_width(p, f);
	return p;
}

char *ft_uitoa_base(unsigned int i, const char* base, unsigned char base_len)
{
	char	buf[33];
	int		cur;

	buf[32] = '\0';
	cur = 32;
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

t_print *init_print_d(t_format *f)
{
	t_print	*p;
	p = (t_print *)ft_mmcalloc(sizeof(t_print), 1);
	if(!p)
		return NULL;
	p->sign = get_sign(f);
	if(p->sign == '-')
		*(int *)f->val *= -1;
	p->p = (const unsigned char *)ft_uitoa_base(*(unsigned int *)f->val, "0123456789", 10);
	size_t n; n = ft_strlen((const char *)p->p);
	if(n > INT_MAX)
		p->inner_len = INT_MAX;
	else if(!*(int *)f->val && f->opt[0] & PRECITION && !f->opt[2])
		p->inner_len = 0;
	else
		p->inner_len = (int)n;
	set_prec(p, f);
	set_f_width_nbr(p, f);
	return p;
}

t_print *init_print_u(t_format *f)
{
	t_print	*p;
	p = (t_print *)ft_mmcalloc(sizeof(t_print), 1);
	if(!p)
		return NULL;
	p->p = (const unsigned char *)ft_uitoa_base(*(unsigned int *)f->val, "0123456789", 10);
	size_t n; n = ft_strlen((const char *)p->p);
	if(n > INT_MAX)
		p->inner_len = INT_MAX;
	else if(!*(int *)f->val && f->opt[0] & PRECITION && !f->opt[2])
		p->inner_len = 0;
	else
		p->inner_len = (int)n;
	set_prec(p, f);
	set_f_width_nbr(p, f);
	return p;
}

t_print *init_print_x(t_format *f)
{
	t_print	*p;
	p = (t_print *)ft_mmcalloc(sizeof(t_print), 1);
	if(!p)
		return NULL;
	p->p = (const unsigned char *)ft_uitoa_base(*(unsigned int *)f->val, "0123456789abcdef", 16);
	size_t n; n = ft_strlen((const char *)p->p);
	if(n > INT_MAX)
		p->inner_len = INT_MAX;
	else if(!*(int *)f->val && f->opt[0] & PRECITION && !f->opt[2])
		p->inner_len = 0;
	else
		p->inner_len = (int)n;
	if(f->opt[0] & ALTER_FORM)
		p->prefix = "0x";
	set_prec(p, f);
	set_f_width_nbr(p, f);
	return p;
}

t_print *init_print_X(t_format *f)
{
	t_print	*p;
	p = (t_print *)ft_mmcalloc(sizeof(t_print), 1);
	if(!p)
		return NULL;
	p->p = (const unsigned char *)ft_uitoa_base(*(unsigned int *)f->val, "0123456789ABCDEF", 16);
	size_t n; n = ft_strlen((const char *)p->p);
	if(n > INT_MAX)
		p->inner_len = INT_MAX;
	else if(!*(int *)f->val && f->opt[0] & PRECITION && !f->opt[2])
		p->inner_len = 0;
	else
		p->inner_len = (int)n;
	if(f->opt[0] & ALTER_FORM)
		p->prefix = "0X";
	set_prec(p, f);
	set_f_width_nbr(p, f);
	return p;
}

t_print *init_print_p(t_format *f)
{
	t_print	*p;
	p = (t_print *)ft_mmcalloc(sizeof(t_print), 1);
	if(!p)
		return NULL;
	if(!*(int *)f->val)
		p->p = (const unsigned char *)"(nil)";
	else
		p->p = (const unsigned char *)ft_ui64toa_base(*(uint64_t *)f->val, "0123456789abcdef", 16);
	size_t n; n = ft_strlen((const char *)p->p);
	if(n > INT_MAX)
		p->inner_len = INT_MAX;
	else
		p->inner_len = (int)n;
	p->prefix = "0x";
	set_prec(p, f);
	set_f_width_nbr(p, f);
	return p;
}

t_print	*norm_fmt(t_format *f)
{
	if(f->mod == 'R')
		return init_print_raw(f);
	if(f->mod == '%')
		return init_print_percent(f);
	if(f->mod == 'c')
		return init_print_c(f);
	if(f->mod == 's')
		return init_print_s(f);
	if(f->mod == 'd')
		return init_print_d(f);
	if(f->mod == 'i')
		return init_print_d(f);
	if(f->mod == 'u')
		return init_print_u(f);
	if(f->mod == 'x')
		return init_print_x(f);
	if(f->mod == 'X')
		return init_print_X(f);
	if(f->mod == 'p')
		return init_print_p(f);
	return NULL;
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
	t_format *fmt; fmt = load_fmt(f, ap);
	if(!fmt)
	{
		set_cnt(EOF);
		return ;
	}
	t_print	*p; 
	p = norm_fmt(fmt);
	if(!p)
	{
		set_cnt(EOF);
		return ;
	}
	print_unit(s, p);
	free_s_print(fmt);
}

int	ft_vfprintf(FILE *s, const char *format, va_list ap)
{
	set_cnt(0);
	while (*format != '\0')
	{
		print_by_unit(s, &format, ap);
		if(get_cnt() == EOF)
			return EOF;
	}
	return (get_cnt());
}
