/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:45:25 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 16:01:33 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "../parse/parse.h"

int	exe(t_prs *parse, int std_in[2], int std_out[2])
{
	if (parse->type == simple_cmd)
		return (exe_simple_cmd(parse, std_in, std_out));
	if (parse->type == Pipe)
		return (exe_pipe(parse, std_in, std_out));
	return (-1);
}
