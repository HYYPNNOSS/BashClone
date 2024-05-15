/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstput_orderly.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 02:13:26 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 20:23:46 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../minishell.h"

t_lst	*lst_put_orderly(t_lst **lst, char *d_name)
{
	t_lst	*new;
	char	*dup;

	dup = ft_strdup(d_name);
	new = ft_lstnew(dup);
	if (!new || !dup)
		return (free(dup), free(new), ft_lstclear(lst, free), NULL);
	return (lst_put_orderly_sorted(lst, new), new);
}
