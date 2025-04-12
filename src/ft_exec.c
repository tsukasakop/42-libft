/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:19:38 by tkondo            #+#    #+#             */
/*   Updated: 2025/01/04 15:30:16 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <_ft_unistd.h>
#include <ft_stdlib.h>

static void	free_dirs(char **dirs)
{
	size_t	i;

	i = 0;
	while (dirs && dirs[i])
	{
		free(dirs[i]);
		i++;
	}
	free(dirs);
}

static const char	*find_path(const char *name)
{
	char	*tmp;
	char	*path;
	char	**dirs;
	size_t	i;

	if (ft_getenv("PATH") == NULL)
		return (NULL);
	dirs = ft_split(ft_getenv("PATH"), ':');
	i = 0;
	while (dirs && dirs[i])
	{
		tmp = ft_strjoin(*dirs, "/");
		path = ft_strjoin(tmp, name);
		free(tmp);
		if (access(path, F_OK) == 0)
		{
			free_dirs(dirs);
			return ((const char *)path);
		}
		free(path);
		i++;
	}
	free_dirs(dirs);
	return (NULL);
}

int	ft_execvp(const char *path, char *const argv[])
{
	const char	*abs_path;
	int			ret;

	if (ft_strchr(path, '/') != NULL)
		return (execve(path, argv, NULL));
	abs_path = find_path(path);
	if (abs_path == NULL)
		return (-1);
	ret = execve(abs_path, argv, NULL);
	free((void *)abs_path);
	return (ret);
}
