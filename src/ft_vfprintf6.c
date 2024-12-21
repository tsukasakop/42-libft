/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf6.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 22:41:55 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/21 10:30:43 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_by_unit(FILE *s, const char **f, va_list ap)
{
	t_print		*p;
	t_format	*fmt;

	fmt = read_fmt(f, ap);
	p = norm_fmt(fmt);
	if (!p || is_overflow(p))
		set_cnt(EOF);
	else
		print_unit(s, p);
	ft_g_mmfree();
}

int	ft_vfprintf(FILE *s, const char *format, va_list ap)
{
	int	cnt;

	set_cnt(0);
	while (*format != '\0')
	{
		print_by_unit(s, &format, ap);
		if (get_cnt() == EOF)
			break ;
	}
	cnt = get_cnt();
	del_cnt();
	return (cnt);
}
