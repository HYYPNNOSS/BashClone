/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 02:12:48 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 16:00:14 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrm(t_lst **lst, t_lst *to_rm)
{
	t_lst	*pre;
	t_lst	*cur;

	pre = NULL;
	cur = *lst;
	while (cur)
	{
		if (cur == to_rm)
		{
			if (pre)
				pre->next = cur->next;
			else
				*lst = cur->next;
			return ;
		}
		pre = cur;
		cur = cur->next;
	}
}
