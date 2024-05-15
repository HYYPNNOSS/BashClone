/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:47:27 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 15:37:03 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**frm_lst_to_str(t_lst *arg_lst)
{
	char	**av;
	int		i;

	av = malloc(sizeof(char *) * (ft_lstsize(arg_lst) + 1));
	if (!av)
		return (av);
	i = 0;
	while (arg_lst)
	{
		av[i] = ft_strdup(arg_lst->content);
		if (!av[i++])
			return (str_free(av), NULL);
		arg_lst = arg_lst->next;
	}
	av[i] = NULL;
	return (av);
}

t_prs	*init_parse(t_parse_type type, t_prs *left, t_prs *right)
{
	t_prs	*parse;

	parse = malloc(sizeof(t_prs));
	if (!parse)
		return (parse);
	parse->left = left;
	parse->right = right;
	parse->type = type;
	parse->ac = 0;
	parse->av = NULL;
	parse->rdr_lst = NULL;
	return (parse);
}

t_prs	*create_node(t_lst **rdr_lst, t_lst **arg_lst)
{
	t_prs	*node;
	char	**av;
	int		ac;

	node = init_parse(simple_cmd, NULL, NULL);
	av = frm_lst_to_str(*arg_lst);
	ac = ft_lstsize(*arg_lst);
	ft_lstclear(arg_lst, free);
	if (!av || !node)
		return (perror("minishell"), free_tree_node(node),
			str_free(av), ft_lstclear(rdr_lst, (t_delfn)free_rdr), NULL);
	node->rdr_lst = *rdr_lst;
	node->av = av;
	node->ac = ac;
	return (node);
}
