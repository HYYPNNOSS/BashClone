/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 02:07:15 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 16:54:52 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strspn(const char *string, const char *charset)
{
	size_t	i;

	i = 0;
	while (string[i] && ft_strchr(charset, string[i]))
		i++;
	return (i);
}
