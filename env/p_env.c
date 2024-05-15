/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 13:28:30 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 17:54:48 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../minishell.h"

static int	env_length(t_lst *lst)
{
	t_envir	*env;
	int		i;

	i = 1;
	while (lst)
	{
		env = lst->content;
		if (env->val)
			i++;
		lst = lst->next;
	}
	return (i);
}

static char	*env_alloc(t_envir *env)
{
	char	*str;
	char	*string;

	string = ft_strjoin(env->name, "=");
	if (!string)
		return (NULL);
	str = ft_strjoin(string, env->val);
	if (!str)
	{
		free(string);
		return (NULL);
	}
	return (str);
}

char	**ft_env_p(void)
{
	char	**env_p;
	t_lst	*lst;
	t_envir	*env;
	int		i;

	i = 0;
	lst = g_sh.lst_env;
	env_p = malloc(sizeof(char *) * env_length(lst));
	if (!env_p)
		return (NULL);
	while (lst)
	{
		env = lst->content;
		if (env->val)
		{
			env_p[i] = env_alloc(env);
			if (!env_p[i])
				break ;
			i++;
		}
		lst = lst->next;
	}
	if (!env_p)
		return (str_free(env_p), NULL);
	return (env_p[i] = NULL, env_p);
}
