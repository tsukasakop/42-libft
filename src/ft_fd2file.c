/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd2file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:59:44 by tkondo            #+#    #+#             */
/*   Updated: 2024/12/21 19:43:58 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_ft_stdio.h"

t_file	*ft_stdin(void)
{
	static unsigned int	has_build;
	static t_file		f;

	if (!has_build)
	{
		ft_fset_fd(&f, STDIN_FILENO);
		has_build = 1;
	}
	return (&f);
}

t_file	*ft_stdout(void)
{
	static unsigned int	has_build;
	static t_file		f;

	if (!has_build)
	{
		ft_fset_fd(&f, STDOUT_FILENO);
		has_build = 1;
	}
	return (&f);
}

t_file	*ft_stderr(void)
{
	static unsigned int	has_build;
	static t_file		f;

	if (!has_build)
	{
		ft_fset_fd(&f, STDERR_FILENO);
		has_build = 1;
	}
	return (&f);
}

t_file	*ft_fd2file(int fd)
{
	t_file	*f;

	if (fd == 0)
		return (ft_stdin());
	if (fd == 1)
		return (ft_stdout());
	if (fd == 2)
		return (ft_stderr());
	f = ft_filenew();
	if (!f)
		return (NULL);
	ft_fset_fd(f, fd);
	return (f);
}
