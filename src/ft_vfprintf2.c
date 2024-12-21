/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/21 10:24:36 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	get_sign(t_format *f)
{
	if (f->u_val.nbr < 0)
		return ('-');
	if (f->s_flag.plus)
		return ('+');
	if (f->s_flag.space)
		return (' ');
	return ('\0');
}

void	set_f_width(t_print *p, t_format *f)
{
	int	f_width;

	f_width = f->field - p->inner_len - p->zero_len;
	if (p->sign)
		f_width--;
	if (p->prefix)
		f_width -= ft_strlen(p->prefix);
	if (f_width < 0)
		return ;
	if (f->s_flag.minus)
		p->r_ws_len = f_width;
	else if (f->s_flag.zero && !f->s_flag.period)
		p->zero_len += f_width;
	else
		p->l_ws_len = f_width;
}

void	set_prec(t_print *p, t_format *f)
{
	int	prec;

	prec = f->prec - p->inner_len;
	if (prec < 0)
		return ;
	if (f->s_flag.period)
		p->zero_len = prec;
	set_f_width(p, f);
}

char	*ft_ui64toa_base(uint64_t i, const char *base, unsigned char base_len)
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
	return (ft_strdup(buf + cur));
}
