/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:27:34 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 16:54:52 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *string, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!string)
		return (NULL);
	i = 0;
	if (ft_strlen(string) < start)
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	if (ft_strlen(string + start) + 1 < len)
		str = ft_calloc(ft_strlen(string + start) + 1, 1);
	else
		str = ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	while (i < len && string[start + i])
	{
		str[i] = string[start + i];
		i++;
	}
	return (str);
}
