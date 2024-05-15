/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:25:48 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 18:25:49 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <limits.h>

static int	ft_execut(char *path, char **av)
{
	char	**env_p;

	env_p = ft_env_p();
	if (!env_p)
		return (-1);
	execve(path, av, env_p);
	str_free(env_p);
	return (-1);
}

static char	*path_join(char *path, char *dir, char *file)
{
	if (*dir == '\0')
		dir = ".";
	path[0] = '\0';
	if (ft_strlcat(path, dir, PATH_MAX) >= PATH_MAX
		|| ft_strlcat(path, "/", PATH_MAX) >= PATH_MAX
		|| ft_strlcat(path, file, PATH_MAX) >= PATH_MAX)
		return (errno = ENAMETOOLONG, NULL);
	return (path);
}

static int	ft_path(char *path, char *path_env, char **av)
{
	char	a_path[PATH_MAX];
	char	*dup;
	char	*str;
	int		access;

	access = 1;
	dup = ft_strdup(path_env);
	if (!dup)
		return (-1);
	str = dup;
	while (str)
	{
		if (path_join(a_path, ft_strsep(&str, ":"), path) == NULL)
			break ;
		ft_execut(a_path, av);
		if (errno == EACCES)
			access = 0;
		else if (errno == ENOENT || errno == ENOTDIR)
			continue ;
		break ;
	}
	if (!access)
		errno = EACCES;
	return (free(dup), -1);
}

int	ft_executve(char *path, char **av)
{
	char	*path_env;

	errno = ENOENT;
	if (!*path)
		return (-1);
	if (ft_strchr(path, '/'))
		return (ft_execut(path, av));
	path_env = ft_env("PATH");
	if (!path_env)
		return (-1);
	return (ft_path(path, path_env, av));
}
