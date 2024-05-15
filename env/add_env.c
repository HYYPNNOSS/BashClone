/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:43:04 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 20:23:46 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../minishell.h"

int	comp_env(t_envir *env1, t_envir *env2)
{
	int	cmp;

	cmp = ft_strcmp(env1->name, env2->name);
	return (cmp);
}

int	add_env(char *name, char *val)
{
	t_lst	*lst;
	t_envir	*env;

	env = envr_init(name, val);
	lst = ft_lstnew(env);
	if (!lst || !env)
	{
		env_free(env);
		ft_lstdelone(lst, NULL);
		return (-1);
	}
	lst_put_orderly_sorted(&g_sh.lst_env, lst);
	return (0);
}
