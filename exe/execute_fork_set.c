/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:44:23 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 14:45:58 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	close_pipe(int std[2])
{
	if (!std)
		return ;
	close(std[0]);
	close(std[1]);
}

static void	fork_pipes_set(int std_in[2], int std_out[2])
{
	if (std_in && dup2(std_in[0], 0) == -1)
	{
		perror("minishell");
		exit(1);
	}
	close_pipe(std_in);
	if (std_out && dup2(std_out[1], 1) == -1)
	{
		perror("minishell");
		exit(1);
	}
	close_pipe(std_out);
}

int	set_fork(int std_in[2], int std_out[2])
{
	int	pid;

	pid = fork();
	if (pid == 0)
		fork_pipes_set(std_in, std_out);
	else if (pid == -1)
		perror("minishell");
	else
		close_pipe(std_in);
	return (pid);
}
