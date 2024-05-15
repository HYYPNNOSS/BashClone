/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_signals.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:44:34 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 16:02:50 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	sig_int_handler(int sig)
{
	rl_replace_line("", 0);
	ft_putstr_fd("\n", 1);
	if (g_sh.exec)
		return ;
	rl_on_new_line();
	rl_redisplay();
	g_sh.exit_s = 128 + sig;
}

static void	sig_quit_handler(int sig)
{
	if (!g_sh.exec)
		return ;
	rl_replace_line("", 0);
	ft_putstr_fd("Quit: ", 1);
	ft_putnbr_fd(sig, 1);
	ft_putstr_fd("\n", 1);
}

void	exe_set_signal(int signals)
{
	signal(SIGINT, sig_int_handler);
	signal(SIGQUIT, sig_quit_handler);
	if (signals)
		rl_catch_signals = 0;
}

int	event(void)
{
	return (0);
}

void	handler(int sig)
{
	if (sig == SIGINT)
	{
		g_sh.exec = -1;
		rl_done = 1;
	}
}
