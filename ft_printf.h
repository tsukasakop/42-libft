/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:52:48 by tkondo            #+#    #+#             */
/*   Updated: 2024/09/18 20:26:45 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stdarg.h>
# include <stdio.h>

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_fileno(FILE *stream);
size_t	ft_fwrite(const void *ptr, size_t size, size_t n_items, FILE *stream);
int		ft_fputc(int c, FILE *stream);
int		ft_fflush(FILE *stream);
int		ft_printf(const char *format, ...);
int		ft_vfprintf(FILE *s, const char *format, va_list ap);

#endif
