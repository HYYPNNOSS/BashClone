/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:43:50 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 16:00:14 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../minishell.h"

int	unset_env(char *name)
{
	t_lst	*lst;

	if (!name || !*name || ft_strchr(name, '='))
		return (errno = EINVAL, -1);
	lst = ft_found(g_sh.lst_env, name);
	if (lst)
	{
		ft_lstrm(&g_sh.lst_env, lst);
		ft_lstdelone(lst, (void *)env_free);
	}
	return (0);
}
