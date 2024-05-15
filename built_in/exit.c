/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:42:03 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 18:29:36 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include <limits.h>

static int	is_num(char *str)
{
	errno = 0;
	if ((ft_atoll(str) == LLONG_MAX || ft_atoll(str) == LLONG_MIN) && errno)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	return (0);
}

int	ft_exit(int ac, char **av)
{
	ft_putstr_fd("exit\n", 1);
	if (ac > 2)
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		return (1);
	}
	if (ac == 1)
		exit(g_sh.exit_s);
	if (!is_num(av[1]))
	{
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (exit(255), 255);
	}
	exit((unsigned char)ft_atoll(av[1]));
}
