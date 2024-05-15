/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:47:24 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 19:47:32 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_tkn	token_int(t_type type, char *str, int len)
{
	t_tkn	token;

	token.str = str;
	token.type = type;
	token.len = len;
	return (token);
}

void	lexer_advence(t_lxr *lexer, int n)
{
	n = ft_strnlen(lexer->line, n);
	lexer->line += n;
	lexer->pos = n;
}

static void	skip_spaces(t_lxr *lexer)
{
	int	n;

	n = 0;
	while (lexer->line[n] == ' ')
		n++;
	lexer_advence(lexer, n);
}

t_tkn	token_peak(t_lxr *lexer)
{
	skip_spaces(lexer);
	if (!*lexer->line)
		return (token_int(EOF_T, NULL, 0));
	return (next_token(lexer));
}

t_tkn	lexer_next(t_lxr *lexer)
{
	t_tkn	token;

	token = token_peak(lexer);
	lexer_advence(lexer, token.len);
	return (token);
}
