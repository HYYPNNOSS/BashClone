/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:46:44 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 15:59:44 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parse/parse.h"

void	str_free(char **str)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_tree_node(t_prs *parse)
{
	if (!parse)
		return ;
	str_free(parse->av);
	ft_lstclear(&parse->rdr_lst, (t_delfn)free_rdr);
	free(parse);
}

void	free_tree(t_prs **parse)
{
	t_prs	*tree;

	tree = *parse;
	if (!tree)
		return ;
	free_tree(&tree->left);
	free_tree(&tree->right);
	free_tree_node(tree);
	*parse = NULL;
}
