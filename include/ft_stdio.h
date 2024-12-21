/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 19:52:48 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/21 20:15:31 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

# ifndef USE_STD_FILE_TYPE

typedef struct s_file
{
	int			_fd;
}				t_file;

# else

typedef FILE	t_file;

# endif

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_fileno(t_file *stream);
int				ft_fflush(t_file *stream);
size_t			ft_fwrite(const void *ptr, size_t size, size_t n_items,
					t_file *stream);
int				ft_fputc(int c, t_file *stream);
int				ft_fputs(const char *c, t_file *stream);
int				ft_printf(const char *format, ...);
int				ft_vfprintf(t_file *s, const char *format, va_list ap);

#endif
