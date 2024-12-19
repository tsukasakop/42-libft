/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_stdio.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 03:11:49 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/17 10:33:13 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _STDIO_FT_H
# define _STDIO_FT_H
# include "ft_stdio.h"
# include "libft.h"

typedef enum e_print_flag t_print_flag;
typedef struct s_format t_format;
typedef struct s_print t_print;

enum e_print_flag
{
	PAD_ZERO = 1,
	ADJUST_LEFT = 2,
	BLANK_PNUM = 4,
	SIGN_NUM = 8,
	ALTER_FORM = 16,
	PRECITION = 32,
};

struct s_format
{
	unsigned char	mod;
	const char			*begin;
	const char			**orig;
	const char			*cur;
	void			*val;
	int				opt[3];
};

struct s_print
{
    char sign;
   const char *prefix;
    int l_ws_len;
    int zero_len;
    int inner_len;
    int r_ws_len;
    const char *base;
    const unsigned char *p;
};

#endif