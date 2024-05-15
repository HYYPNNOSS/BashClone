/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_put_orderly_new.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 02:06:25 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 20:27:25 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	lst_put_orderly_new(t_lst **lst, t_lst *new, t_cmpfn cmpfn)
{
	t_lst	*cur;
	t_lst	*pre;

	cur = *lst;
	if (!cur || cmpfn(cur->content, new->content) > 0)
		ft_lstadd_front(lst, new);
	else
	{
		pre = cur;
		cur = cur->next;
		while (cur && cmpfn(cur->content, new->content) <= 0)
		{
			pre = cur;
			cur = cur->next;
		}
		new->next = cur;
		pre->next = new;
	}
}
