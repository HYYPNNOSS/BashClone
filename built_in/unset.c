/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_exe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:42:30 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 17:52:29 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	unset(char *av)
{
	int	i;

	i = 1;
	if (!ft_isalpha(*av) && *av != '_')
		return (ft_putstr_fd("minishell: unset: '", 2), ft_putstr_fd(av, 2),
			ft_putstr_fd("': not a valid identifier\n", 2), 1);
	while (ft_isalnum(av[i]) || av[i] == '_')
		i++;
	if (av[i] != '\0')
		return (ft_putstr_fd("minishell: unset: '", 2), ft_putstr_fd(av, 2),
			ft_putstr_fd("': not a valid identifier", 2), 1);
	if (unset_env(av))
		return (ft_putstr_fd("minishell: unset: '", 2), ft_putstr_fd(av, 2),
			perror("': "), 1);
	return (0);
}

int	ft_unset(int ac, char **av)
{
	while (*++av)
		unset(*av);
	(void)ac;
	return (0);
}
