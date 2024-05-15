/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:28:20 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 18:28:21 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_lst	*ft_found(t_lst *lst_env, char *name)
{
	t_envir	*env;

	while (lst_env)
	{
		env = lst_env->content;
		if (!ft_strcmp(env->name, name))
			return (lst_env);
		lst_env = lst_env->next;
	}
	return (NULL);
}
