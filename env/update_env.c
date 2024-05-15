/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:43:54 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 17:12:36 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	update_env(t_envir *env, char *val)
{
	char	*value_dup;

	if (env->val && !val)
		return (0);
	value_dup = NULL;
	if (val)
	{
		value_dup = ft_strdup(val);
		if (!value_dup)
			return (-1);
	}
	return (free(env->val), env->val = value_dup, 0);
}
