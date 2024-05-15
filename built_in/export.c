/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_exe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:42:08 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 17:50:31 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	export_printer(void)
{
	t_lst	*lst;
	t_envir	*env;

	lst = g_sh.lst_env;
	while (lst)
	{
		env = lst->content;
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(env->name, 1);
		if (env->val)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(env->val, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		lst = lst->next;
	}
}

static	void	error_printer(char *name, char *av)
{
	ft_putstr_fd("minishell: export: '", 2);
	ft_putstr_fd(name, 2);
	ft_putstr_fd("=", 2);
	ft_putstr_fd(av, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
}

static int	export(char *av)
{
	char	*name;
	int		i;

	i = 1;
	name = ft_strsep(&av, "=");
	if (!ft_isalpha(*name) && *name != '_')
		return (error_printer(name, av), 1);
	while (ft_isalnum(name[i]) || name[i] == '_')
		i++;
	if (name[i] == '+' && name[i + 1] == '\0')
	{
		name[i] = '\0';
		if (ft_env(name))
			av = ft_strjoin(ft_env(name), av);
	}
	if (name[i] != '\0')
		return (error_printer(name, av), 1);
	if (envr_set(name, av))
		return (ft_putstr_fd("minishell: export: '", 2), ft_putstr_fd(name, 2),
			ft_putstr_fd("=", 2), ft_putstr_fd(av, 2), perror("': "), 1);
	return (0);
}

int	ft_export(int ac, char **av)
{
	int	exit_s;

	exit_s = 0;
	if (ac == 1)
		return (export_printer(), 0);
	av++;
	while (*av)
		if (export(*av++))
			exit_s = 1;
	return (exit_s);
}
