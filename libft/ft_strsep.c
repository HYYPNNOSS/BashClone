/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 02:08:35 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 16:54:52 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsep(char **str, const char *sep)
{
	char	*string;
	char	*end;

	string = *str;
	if (!string)
		return (NULL);
	end = string + ft_strcspn(string, sep);
	if (*end)
		*end++ = '\0';
	else
		end = NULL;
	*str = end;
	return (string);
}
