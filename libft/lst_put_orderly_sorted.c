/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_put_orderly_sorted.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 02:05:11 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 16:00:14 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_put_orderly_sorted(t_lst **lst, t_lst *new)
{
	t_lst	*cur;
	t_lst	*pre;

	cur = *lst;
	if (!cur || ft_strcmp(cur->content, new->content) > 0)
		ft_lstadd_front(lst, new);
	else
	{
		pre = cur;
		cur = cur->next;
		while (cur && ft_strcmp(cur->content, new->content) <= 0)
		{
			pre = cur;
			cur = cur->next;
		}
		new->next = cur;
		pre->next = new;
	}
}
