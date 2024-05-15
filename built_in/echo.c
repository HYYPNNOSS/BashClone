/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-moun <eel-moun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:41:47 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 01:41:48 by eel-moun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_check_option(char *av)
{
	if (*av != '-' || *++av != 'n')
		return (0);
	av++;
	while (*av == 'n')
		av++;
	if (*av == '\0')
		return (1);
	return (0);
}

int	ft_echo(int ac, char **av)
{
	int	i;

	(void)ac;
	av++;
	i = 1;
	while (*av)
	{
		if (!ft_check_option(*av))
			break ;
		i = 0;
		av++;
	}
	while (*av)
	{
		ft_putstr_fd(*av, 1);
		av++;
		if (*av)
			ft_putstr_fd(" ", 1);
	}
	if (i)
		ft_putstr_fd("\n", 1);
	return (0);
}
