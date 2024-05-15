/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:44:29 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 18:02:25 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	exe_pipe(t_prs *parse, int std_in[2], int std_out[2])
{
	int	exe_pipe[2];
	int	pid_l;
	int	pid_r;

	if (pipe(exe_pipe))
		return (perror("minishll"), -1);
	pid_l = simple_cmd_pid(parse->left, std_in, exe_pipe);
	if (pid_l == -1)
	{
		close_pipe(exe_pipe);
		return (-1);
	}
	pid_r = exe(parse->right, exe_pipe, std_out);
	if (pid_r == -1)
		close_pipe(exe_pipe);
	waitpid(pid_l, NULL, 0);
	return (pid_r);
}
