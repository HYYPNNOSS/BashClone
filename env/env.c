/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:43:32 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 03:24:09 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../minishell.h"

char	*ft_env_n(char *name, int i)
{
	t_lst	*lst;
	t_envir	*env;

	if (name)
		i = ft_strnlen(name, i);
	if (!name || !i || ft_memchr(name, '=', i))
		return (errno = EINVAL, NULL);
	lst = g_sh.lst_env;
	while (lst)
	{
		env = lst->content;
		if (!ft_strncmp(env->name, name, i) && env->name[i] == '\0')
			return (env->val);
		lst = lst->next;
	}
	return (NULL);
}

char	*ft_env(char *name)
{
	t_lst	*lst;
	t_envir	*env;

	if (!name || !*name || ft_strchr(name, '='))
		return (errno = EINVAL, NULL);
	lst = g_sh.lst_env;
	while (lst)
	{
		env = lst->content;
		if (!ft_strcmp(env->name, name))
			return (env->val);
		lst = lst->next;
	}
	return (NULL);
}
