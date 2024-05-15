/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:27:18 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 18:27:19 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "../minishell.h"

int	envr_set(char *name, char *val)
{
	t_lst	*lst;

	if (!name || !*name || ft_strchr(name, '='))
		return (errno = EINVAL, -1);
	lst = ft_found(g_sh.lst_env, name);
	if (!lst)
		return (add_env(name, val));
	return (update_env(lst->content, val));
}
