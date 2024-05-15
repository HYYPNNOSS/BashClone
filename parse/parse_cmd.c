/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:25:00 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 18:25:01 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "lexer.h"

t_lst	*command_pasre_elem(t_lxr *lexer, t_lst **rdr_lst, t_lst **arg_lst)
{
	t_lst	*lst;

	if (token_peak(lexer).type == STR)
	{
		lst = global_parse(lexer_next(lexer));
		if (lst)
			ft_lstadd_back(arg_lst, lst);
		return (lst);
	}
	else
		return (redirection_parse(lexer, rdr_lst));
}

t_prs	*command_pasre(t_lxr *lexer)
{
	t_lst	*cmd_e;
	t_lst	*rdr_lst;
	t_lst	*arg_lst;

	rdr_lst = NULL;
	arg_lst = NULL;
	cmd_e = command_pasre_elem(lexer, &rdr_lst, &arg_lst);
	while (cmd_e && cmd_e != RULE_E)
		cmd_e = command_pasre_elem(lexer, &rdr_lst, &arg_lst);
	if (!cmd_e)
		return (ft_lstclear(&rdr_lst, (t_delfn)free_rdr),
			ft_lstclear(&arg_lst, (t_delfn)free), NULL);
	if (!rdr_lst && !arg_lst)
		return (RULE_E);
	return (create_node(&rdr_lst, &arg_lst));
}
