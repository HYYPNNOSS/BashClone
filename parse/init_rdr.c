/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdr_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:21:40 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 18:21:45 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../minishell.h"

static	int	write_heredoc_line(char *file, int fd, char *line, bool expa)
{
	char	*env;

	env = NULL;
	if (expa)
	{
		env = expand(line);
		if (!env)
			return (close(fd), unlink(file), free(file), free(line), -1);
		return (ft_putstr_fd(env, fd), ft_putchar_fd('\n', fd), free(env), 0);
	}
	return (ft_putstr_fd(line, fd), ft_putchar_fd('\n', fd), 0);
}

static	int	read_heredoc(char *file, char *delime, bool expand)
{
	char	*line;
	int		fd;

	rl_event_hook = event;
	signal(SIGINT, handler);
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		return (ft_putstr_fd("minishell: ", 2), ft_putstr_fd(file, 2),
			ft_putstr_fd(": ", 2), perror(NULL), fd);
	while (1)
	{
		line = readline("> ");
		if (!line)
			return (0);
		if (g_sh.exec == -1)
			return (0);
		if (!strcmp(line, delime))
			break ;
		if (write_heredoc_line(file, fd, line, expand))
			return (-1);
		free(line);
	}
	return (free(line), close(fd), 0);
}

static char	*r_i_filename(t_tkn str)
{
	static int	n = 0;
	char		*n_str;
	char		*delimit;
	char		*file;
	bool		expand;

	expand = !ft_memchr(str.str, ENC_SQ, str.len);
	expand = (expand && !ft_memchr(str.str, ENC_DQ, str.len));
	n_str = ft_itoa(n);
	delimit = ft_substr(str.str, 0, str.len);
	if (delimit)
		enc_remove_quotes(delimit);
	if (n_str)
		file = ft_strjoin("/tmp/minishell-heredoc-", n_str);
	free(n_str);
	if (!delimit || !n_str || !file || read_heredoc(file, delimit, expand))
		return (perror("minishell"), free(delimit), free(file), NULL);
	free(delimit);
	return (n++, file);
}

static char	*filename(t_tkn str)
{
	t_lst	*file;
	char	*string;

	file = global_parse(str);
	if (!file)
		return (NULL);
	if (ft_lstsize(file) != 1)
		return (ft_putstr_fd("error redirection in: ", 2),
			ft_putstr_fd(str.str, 2), ft_lstclear(&file, free), NULL);
	string = file->content;
	free(file);
	return (string);
}

t_rdr	*redirection_init(t_rdr_type rdr_type, t_tkn str)
{
	t_rdr	*rdr;

	rdr = malloc(sizeof(t_rdr));
	if (!rdr)
		return (perror("minishell"), NULL);
	rdr->type = rdr_type;
	if (rdr_type == R_I)
		rdr->rdr = r_i_filename(str);
	else
		rdr->rdr = filename(str);
	if (!rdr->rdr)
	{
		free(rdr);
		return (NULL);
	}
	return (rdr);
}
