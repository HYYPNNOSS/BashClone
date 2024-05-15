/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 02:14:21 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 17:21:07 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <errno.h>

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;
	int			nb;
	int			i;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (ft_isdigit(str[i]))
	{
		nb = (str[i++] - 48);
		if (sign == 1 && (LLONG_MAX - res) / 10 < res)
			return (errno = ERANGE, LLONG_MAX);
		if (sign == -1 && (LLONG_MIN + res) / 10 > res)
			return (errno = ERANGE, LLONG_MIN);
		res = res * 10 + nb * sign;
	}
	return (res);
}
