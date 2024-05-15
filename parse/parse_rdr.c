/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rdr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:22:08 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 18:22:11 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"

void	free_rdr(t_rdr *rdr)
{
	if (rdr->type == R_I)
		unlink(rdr->rdr);
	free(rdr->rdr);
	free(rdr);
}

static t_rdr_type	get_rdr_type(t_tkn rdr)
{
	if (rdr.type == l_R_I)
		return (R_I);
	if (rdr.type == l_R_O)
		return (R_O);
	if (rdr.type == l_I)
		return (I);
	if (rdr.type == l_O)
		return (O);
	return (0);
}

t_lst	*redirection_add(t_rdr_type rdr_type, t_tkn str, t_lst **arg_lst)
{
	t_lst	*new;
	t_rdr	*rdr;

	rdr = redirection_init(rdr_type, str);
	if (!rdr)
		return (NULL);
	new = ft_lstnew(rdr);
	if (!new)
		return (perror("minishell"), free_rdr(rdr), NULL);
	ft_lstadd_back(arg_lst, new);
	return (new);
}

t_lst	*redirection_parse(t_lxr *lexer, t_lst **rdr_lst)
{
	t_tkn	rdr;
	t_tkn	str;

	rdr = token_peak(lexer);
	if (!get_rdr_type(rdr))
		return (RULE_E);
	lexer_next(lexer);
	str = lexer_next(lexer);
	if (str.type != STR)
		return (print_err(lexer, str), NULL);
	return (redirection_add(get_rdr_type(rdr), str, rdr_lst));
}
