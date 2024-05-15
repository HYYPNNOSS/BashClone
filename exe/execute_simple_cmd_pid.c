/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_cmd_pid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:44:40 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 14:46:27 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	simple_cmd_pid(t_prs *parse, int std_in[2], int std_out[2])
{
	t_blt_in	blt_in;
	int			pid;

	pid = set_fork(std_in, std_out);
	if (pid)
		return (pid);
	if (!parse->av && !parse->av[0])
		exit(0);
	blt_in = ft_check_built_in(parse->av);
	if (blt_in)
		return (ft_built_in(parse, blt_in), exit(g_sh.exit_s), 0);
	if (ft_check_rdr(parse->rdr_lst, NULL) == -1)
		exit (1);
	ft_executve(parse->av[0], parse->av);
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(parse->av[0], 2);
	if (ft_putstr_fd(": ", 2), errno == ENOENT && !ft_strchr(parse->av[0], '/'))
		ft_putstr_fd("command not found\n", 2);
	else
		perror(NULL);
	if (errno == EACCES)
		exit(126);
	if (errno == ENOENT)
		exit(127);
	exit(1);
}
