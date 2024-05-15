/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enc_rm_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:25:17 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 18:25:18 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*enc_remove_quotes(char *str)
{
	char	*string;
	int		n;

	string = str;
	n = ft_strlen(string) + 1;
	while (*string)
	{
		if (*string == ENC_SQ || *string == ENC_DQ)
			ft_memcpy(string, string + 1, n - 1);
		else
			string++;
		n--;
	}
	return (str);
}
