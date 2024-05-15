/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:04:21 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 16:54:52 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *string, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!string || !f)
		return (NULL);
	i = 0;
	str = ft_calloc(ft_strlen(string) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (string[i])
	{
		str[i] = f(i, string[i]);
		i++;
	}
	return (str);
}
