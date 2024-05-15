/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:41:54 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 18:33:48 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_exec_env(int ac, char **av)
{
	t_lst	*lst;
	t_envir	*env;

	(void) ac;
	(void) av;
	lst = g_sh.lst_env;
	while (lst)
	{
		env = lst->content;
		if (env->val)
			printf("%s=%s\n", env->name, env->val);
		lst = lst->next;
	}
	return (0);
}
