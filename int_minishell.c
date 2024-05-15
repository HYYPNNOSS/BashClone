/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_minishell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:46:40 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 20:50:28 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env/env.h"

t_sh	g_sh;

int	creat_env(char **env)
{
	char	*name;
	t_envir	*t_envir;
	t_lst	*lst;

	while (*env)
	{
		name = ft_strsep(&*env, "=");
		t_envir = envr_init(name, *env);
		lst = ft_lstnew(t_envir);
		if (!t_envir || !lst)
			return (env_free(t_envir), free(lst), -1);
		lst_put_orderly_new(&g_sh.lst_env, lst, (t_cmpfn)comp_env);
		env++;
	}
	return (0);
}

int	shlvl_env(void)
{
	char	*val;

	val = ft_env("SHLVL");
	if (val)
	{
		val = ft_itoa(ft_atoi(val) + 1);
		if (!val || envr_set("SHLVL", val))
			return (free(val), -1);
		free(val);
	}
	else
		if (envr_set("SHLVL", "1"))
			return (-1);
	return (0);
}

int	int_minishell(int ac, char **av, char **env)
{
	g_sh.ac = ac;
	g_sh.av = av;
	g_sh.exec = 0;
	g_sh.exit_s = 0;
	g_sh.lst_env = NULL;
	if (creat_env(env) || shlvl_env() || envr_set("SHELL", av[0]))
		return (perror("minishell"),
			ft_lstclear(&g_sh.lst_env, (t_delfn)env_free), -1);
	return (0);
}
