/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_exe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:42:16 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 18:28:48 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "sys/param.h"

int	ft_pwd(int ac, char **av)
{
	char	cwd[MAXPATHLEN];

	if (getcwd(cwd, MAXPATHLEN))
		ft_putstr_fd(cwd, 1);
	else
	{
		perror("minishell: pwd");
		return (1);
	}
	ft_putstr_fd("\n", 1);
	return ((void)ac, (void)av, 0);
}
