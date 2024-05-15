/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:45:20 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 18:05:10 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"
#include "../minishell.h"

int	exe_waitpid(int pid)
{
	pid_t	wait;
	int		status;

	wait = waitpid(pid, &status, 0);
	if (wait == -1)
		return (wait);
	if (WIFEXITED(status))
		g_sh.exit_s = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
		g_sh.exit_s = WTERMSIG(status);
	else
		g_sh.exit_s = 1;
	return (0);
}

int	exe_simple_cmd(t_prs *parse, int std_in[2], int std_out[2])
{
	t_blt_in	blt_in;
	char		**av;
	int			pid;

	blt_in = ft_check_built_in(parse->av);
	if (blt_in && !std_in && !std_out)
	{
		return (ft_built_in(parse, blt_in));
	}
	pid = simple_cmd_pid(parse, std_in, std_out);
	av = parse->av;
	if (pid == -1)
		return (-1);
	if (av && av[0] && !ft_strcmp(g_sh.av[0], av[0]))
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	if (exe_waitpid(pid))
		return (-1);
	return (exe_set_signal(0), 0);
}
