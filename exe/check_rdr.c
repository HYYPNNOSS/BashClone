/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rdr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:26:16 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 18:26:17 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"

static	int	file_opener(t_rdr *rdr)
{
	int	fd;

	fd = -1;
	if (rdr->type == I || rdr->type == R_I)
		fd = open(rdr->rdr, O_RDONLY);
	else if (rdr->type == R_O)
		fd = open(rdr->rdr, O_WRONLY | O_APPEND | O_CREAT, 0664);
	else if (rdr->type == O)
		fd = open(rdr->rdr, O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (fd == -1)
		return (ft_putstr_fd("minishell:", 2), ft_putstr_fd(rdr->rdr, 2),
			ft_putstr_fd(":", 2), perror(NULL), -1);
	return (fd);
}

int	reset_stdio(int stdio[2])
{
	if (!stdio)
		return (0);
	if (dup2(stdio[0], 0) == -1 || dup2(stdio[1], 1) == -1)
		return (perror("minishell"), -1);
	return (0);
}

static	int	stdio_dup(int stdio[2])
{
	if (!stdio)
		return (0);
	stdio[0] = dup(0);
	if (stdio[0] == -1)
		return (perror("minishell"), -1);
	stdio[1] = dup(1);
	if (stdio[1] == -1)
		return (perror("minishell"), -1);
	return (0);
}

static	int	stdio_duplicator2(t_rdr *rdr, int fd)
{
	int	fd_dup2;

	fd_dup2 = -1;
	if (rdr->type == R_I || rdr->type == I)
		fd_dup2 = dup2(fd, 0);
	else
		fd_dup2 = dup2(fd, 1);
	if (fd_dup2 == -1)
		perror("minishell");
	return (fd_dup2);
}

int	ft_check_rdr(t_lst *rdr_lst, int stdio[2])
{
	int	fd[2];

	if (stdio_dup(stdio))
		return (-1);
	while (rdr_lst)
	{
		fd[0] = file_opener(rdr_lst->content);
		fd[1] = stdio_duplicator2(rdr_lst->content, fd[0]);
		if (fd[0] == -1 || fd[1] == -1)
			return (close(fd[0]), reset_stdio(stdio), -1);
		close(fd[0]);
		rdr_lst = rdr_lst->next;
	}
	return (0);
}
