/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_token.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:47:17 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 19:47:32 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

t_lxr	lexer_int(char *line)
{
	t_lxr	lexer;

	lexer.line = line;
	lexer.pos = 0;
	lexer.error = 0;
	return (lexer);
}

static t_tkn	token_check(t_lxr *lexer, char *str, t_type type)
{
	if (!ft_strncmp(lexer->line, str, ft_strlen(str)))
		return (token_int(type, str, ft_strlen(str)));
	lexer->error = L_EOT;
	return (token_int(ERROR, NULL, 0));
}

static t_tkn	string_check(t_lxr *lexer)
{
	char	*str;
	int		i;
	int		mod;

	i = 0;
	mod = UNQUOTED;
	str = lexer->line;
	while (str[i] && (mod != UNQUOTED || !ft_strchr(METACH, str[i])))
		mod = enc_mode_switch(mod, str[i++]);
	if (i == 0)
		return (lexer->error = L_EOT, token_int(ERROR, NULL, 0));
	if (mod != UNQUOTED)
		return (lexer->error = L_EOF, token_int(ERROR, NULL, 0));
	return (token_int(STR, lexer->line, i));
}

t_tkn	next_token(t_lxr *lexer)
{
	t_tkn	token;

	token = token_check(lexer, "|", PIPE);
	if (token.type == ERROR)
		token = token_check(lexer, "<<", l_R_I);
	if (token.type == ERROR)
		token = token_check(lexer, "<", l_I);
	if (token.type == ERROR)
		token = token_check(lexer, ">>", l_R_O);
	if (token.type == ERROR)
		token = token_check(lexer, ">", l_O);
	if (token.type == ERROR)
		token = string_check(lexer);
	return (token);
}
