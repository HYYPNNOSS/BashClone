/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:53:26 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 16:54:52 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *string, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!string)
		return ;
	i = 0;
	while (*string)
	{
		f(i, string);
		string++;
		i++;
	}
}
