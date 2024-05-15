/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:27:53 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 18:28:09 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

t_envir	*envr_init(char *name, char *val)
{
	t_envir	*env;
	char	*name_dup;
	char	*value_dup;

	env = malloc(sizeof(t_envir));
	name_dup = ft_strdup(name);
	value_dup = NULL;
	if (val)
		value_dup = ft_strdup(val);
	if (!env || !name || (val && !value_dup))
	{
		free(env);
		free(name_dup);
		free(value_dup);
		return (NULL);
	}
	return (env->name = name_dup, env->val = value_dup, env);
}
