/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:46:32 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 19:47:32 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse/parse.h"
#include "parse/lexer.h"

t_prs	*parse_line(t_lxr *lexer)
{
	t_tkn	token;
	t_prs	*pipeline;

	pipeline = parse_pipline(lexer);
	if (!pipeline || pipeline == RULE_E)
		return (pipeline);
	token = lexer_next(lexer);
	if (token.type != EOF_T)
	{
		print_err(lexer, token);
		return (free_tree(&pipeline), pipeline);
	}
	return (pipeline);
}

t_prs	*parse(char *line)
{
	t_prs	*parse;
	t_lxr	lexer;

	line = expand(enc_quotes(line));
	lexer = lexer_int(line);
	parse = parse_line(&lexer);
	free(line);
	if (!parse || parse == RULE_E)
		return (NULL);
	return (parse);
}
