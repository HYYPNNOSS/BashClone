/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_exe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:41:35 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 17:23:39 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <sys/param.h>

static	int	home(void)
{
	if (!ft_env("HOME"))
	{
		ft_putstr_fd("minishell: cd: HOME not set\n", 2);
		return (-1);
	}
	return (0);
}

int	ft_cd(int ac, char **av)
{
	char	old_pwd[MAXPATHLEN];
	char	new_pwd[MAXPATHLEN];
	char	*dest;

	if (ac == 1 && home())
		return (1);
	if (ac == 1)
		dest = ft_env("HOME");
	else
		dest = av[1];
	old_pwd[0] = '\0';
	getcwd(old_pwd, MAXPATHLEN);
	if (chdir(dest))
		return (ft_putstr_fd("minishell: cd: ", 2), ft_putstr_fd(dest, 2),
			perror(" "), 1);
	if (!getcwd(new_pwd, MAXPATHLEN))
		return (ft_putstr_fd("minishell: cd: ", 2),
			ft_putstr_fd("error retieving current directory: ", 2),
			ft_putstr_fd("getcwd: cannot access parent directories: ", 2),
			perror(NULL), 1);
	if (!ft_strlen(old_pwd) && ft_env("PWD"))
		ft_strlcpy(old_pwd, ft_env("PWD"), MAXPATHLEN);
	if (envr_set("OLDPWD", old_pwd) || envr_set("PWD", new_pwd))
		return (ft_putstr_fd("minishell: cd: ", 2), perror(NULL), 1);
	return (0);
}
