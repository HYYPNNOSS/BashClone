/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_built_in.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:26:27 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 18:26:28 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_blt_in	ft_check_built_in(char **av)
{
	if (!av || !av[0])
		return (NULL);
	if (!ft_strcmp(av[0], "echo"))
		return (ft_echo);
	if (!ft_strcmp(av[0], "cd"))
		return (ft_cd);
	if (!ft_strcmp(av[0], "pwd"))
		return (ft_pwd);
	if (!ft_strcmp(av[0], "export"))
		return (ft_export);
	if (!ft_strcmp(av[0], "unset"))
		return (ft_unset);
	if (!ft_strcmp(av[0], "env"))
		return (ft_exec_env);
	if (!ft_strcmp(av[0], "exit"))
		return (ft_exit);
	return (NULL);
}
