/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:52:48 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/10 23:09:45 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H
# include <stddef.h>

int		ft_atoi(const char *str);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);

#endif
