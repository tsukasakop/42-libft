/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_stdio.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:11:49 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/20 15:19:04 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_STDIO_H
# define _FT_STDIO_H
# include "ft_stdio.h"
# include "libft.h"

typedef struct s_format		t_format;
typedef struct s_print		t_print;

struct						s_format
{
	unsigned char			mod;
	union
	{
		int					nbr;
		void				*ptr;
	} u_val;
	struct
	{
		unsigned int zero: 1;
		unsigned int minus: 1;
		unsigned int space: 1;
		unsigned int plus: 1;
		unsigned int num: 1;
		unsigned int period: 1;
	} s_flag;
	int prec;
	int field;
};

struct						s_print
{
	char					sign;
	const char				*prefix;
	int						l_ws_len;
	int						zero_len;
	int						inner_len;
	int						r_ws_len;
	const char				*base;
	const unsigned char		*p;
};

#endif
