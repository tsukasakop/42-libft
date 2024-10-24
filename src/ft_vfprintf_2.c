/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:43:27 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/19 15:00:49 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

static int	print_per(s_print *p, int do_print)
{
	if (ft_fputc_f('%', p->s, do_print) == EOF)
		return (EOF);
	return (1);
}

static unsigned char	curc(s_print *p)
{
	return (*(p->cur));
}

static unsigned char	step_cur(s_print *p)
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
