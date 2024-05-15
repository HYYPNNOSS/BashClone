/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:46:10 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 18:18:24 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse/parse.h"

static void	ft_free_int_minishell(t_lst **lst_env)
{
	t_lst	*tmp;

	while (*lst_env)
	{
		tmp = (*lst_env)->next;
		env_free((*lst_env)->content);
		free(*lst_env);
		*lst_env = tmp;
	}
}

int	main(int ac, char **av, char **env)
{
	char	*line;
	t_prs	*p;

	if (int_minishell(ac, av, env))
		return (1);
	exe_set_signal(1);
	line = readline("minishell> ");
	while (line)
	{
		if (ft_strspn(line, " \t\n") < ft_strlen(line))
			add_history(line);
		p = parse(line);
		if (p)
		{
			g_sh.exec = 1;
			if (exe(p, NULL, NULL))
				g_sh.exit_s = 1;
			g_sh.exec = 0;
		}
		free_tree(&p);
		free(line);
		line = readline("minishell> ");
	}
	ft_putstr_fd("exit\n", 1);
	return (ft_free_int_minishell(&g_sh.lst_env), g_sh.exit_s);
}
