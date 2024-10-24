/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:44:05 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/19 14:47:13 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

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
