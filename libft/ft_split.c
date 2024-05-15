/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 00:42:32 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 16:54:52 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *string, char c)
{
	size_t	num;

	num = 0;
	while (*string)
	{
		if (*string != c)
			num++;
		while (*string != c && *string)
			string++;
		while (*string == c && *string)
			string++;
	}
	return (num);
}

static int	freeall(char *str, char **str0)
{
	int	i;

	i = 0;
	if (!str)
	{
		while (str0[i])
		{
			free(str0[i]);
			i++;
		}
		free(str0);
		return (1);
	}
	return (0);
}

char	**ft_split(char const *string, char c)
{
	char	**str;
	int		len;
	int		index;
	int		j;

	if (!string)
		return (NULL);
	j = count(string, c);
	index = 0;
	str = ft_calloc((j + 1), sizeof(char *));
	if (!str)
		return (NULL);
	while (*string && index < j)
	{
		while (*string == c && *string)
			string++;
		len = 0;
		while (*string != c && *string && ++len)
			string++;
		str[index++] = ft_substr(string - len, 0, len);
		if (freeall(str[index - 1], str))
			return (NULL);
	}
	return (str);
}
