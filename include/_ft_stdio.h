/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_stdio.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:11:49 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/16 18:00:01 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STDIO_FT_H
# define _STDIO_FT_H
# include "ft_stdio.h"
# include "libft.h"

typedef enum e_print_flag
{
	PAD_ZERO = 1,
	ADJUST_LEFT = 2,
	BLANK_PNUM = 4,
	SIGN_NUM = 8,
	ALTER_FORM = 16,
	PRECITION = 32,
}					t_print_flag;

typedef struct t_print
{
	unsigned char	mod;
//	char			**orig;
	char			*cur;
	void			*val;
	int				opt[3];
	FILE			*s;
	int				(*print_val)(struct t_print *, int);
}					s_print;
#endif
