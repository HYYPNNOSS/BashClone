/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_built_in.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:44:13 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 14:26:14 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"
#include "../minishell.h"

int	ft_built_in(t_prs *parse, t_blt_in blt_in)
{
	int	stdio[2];
	int	i;

	i = ft_check_rdr(parse->rdr_lst, stdio);
	if (i)
		return (-1);
	g_sh.exit_s = blt_in(parse->ac, parse->av);
	i = reset_stdio(stdio);
	if (i)
		return (-1);
	return (0);
}
