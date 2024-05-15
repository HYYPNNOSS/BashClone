/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_pipline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:47:06 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 19:51:45 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"
#include "../minishell.h"

void	print_err(t_lxr *lexer, t_tkn token)
{
	if (token.type == EOF_T)
		ft_putstr_fd("minishell: syntax error: unexpected token\n", 2);
	else if (token.type == ERROR)
	{
		if ((*lexer).error == L_EOF)
			ft_putstr_fd("minishell: syntax error: unexpected end of file\n", 2);
		else if ((*lexer).error == L_EOT)
		{
			ft_putstr_fd("minishell: syntax error: ", 2);
			ft_putstr_fd("unrecognized token at position ", 2);
			ft_putnbr_fd((*lexer).pos + 1, 2);
			ft_putstr_fd("\n", 2);
		}
	}
	else
	{
		ft_putstr_fd("minishell: syntax error near unexpected token '", 2);
		write(2, token.str, token.len);
		ft_putstr_fd("'\n", 2);
	}
}

t_prs	*pipe_parse(t_lxr *lexer)
{
	t_prs	*pipeline;
	t_prs	*pipe;

	if (token_peak(lexer).type != PIPE)
		return (RULE_E);
	lexer_next(lexer);
	pipeline = parse_pipline(lexer);
	if (pipeline == RULE_E)
		return (print_err(lexer, token_peak(lexer)), NULL);
	pipe = init_parse(Pipe, NULL, pipeline);
	if (!pipe && !pipeline)
		return (free_tree(&pipe), free_tree(&pipeline), NULL);
	return (pipe);
}

t_prs	*parse_pipline(t_lxr *lexer)
{
	t_prs	*cmd;
	t_prs	*pipe;

	cmd = command_pasre(lexer);
	if (cmd && cmd != RULE_E)
	{
		pipe = pipe_parse(lexer);
		if (pipe == RULE_E)
			return (cmd);
		if (pipe)
			pipe->left = cmd;
		else
			free_tree(&cmd);
		return (pipe);
	}
	return (cmd);
}
