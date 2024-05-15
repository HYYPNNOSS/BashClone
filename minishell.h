/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:46:27 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 19:54:49 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "parse/parse.h"
# include "libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

typedef int			(*t_blt_in)(int, char **);

typedef struct s_sh
{
	int				ac;
	char			**av;
	t_lst			*lst_env;
	unsigned char	exit_s;
	int				exec;
}	t_sh;

extern t_sh			g_sh;

int			int_minishell(int ac, char **av, char **env);
t_blt_in	ft_check_built_in(char **av);
int			ft_built_in(t_prs *parse, t_blt_in blt_in);
int			ft_check_rdr(t_lst *rdr_lst, int stdio[2]);
int			ft_executve(char *path, char **envp);
int			reset_stdio(int stdio[2]);
void		close_pipe(int std[2]);
int			ft_echo(int ac, char **av);
int			ft_cd(int ac, char **av);
int			ft_pwd(int ac, char **av);
int			ft_exec_env(int ac, char **av);
int			ft_exit(int ac, char **av);
int			ft_unset(int ac, char **av);
int			ft_export(int ac, char **av);
int			simple_cmd_pid(t_prs *parse, int std_in[2], int std_out[2]);
int			exe_simple_cmd(t_prs *parse, int std_in[2], int std_out[2]);
int			exe_pipe(t_prs *parse, int std_in[2], int std_out[2]);
int			set_fork(int std_in[2], int std_out[2]);
int			ft_executve(char *path, char **envp);
int			exe(t_prs *parse, int std_in[2], int std_out[2]);
int			exe_waitpid(int pid);
void		exe_set_signal(int signals);

#endif