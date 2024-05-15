/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enc_quotes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:47:36 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 16:54:52 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*enc_quotes(char *line)
{
	int		mod;
	char	*string;

	mod = UNQUOTED;
	string = line;
	while (*string)
	{
		mod = mode_switch(mod, *string);
		if (*string == '"' && (mod == D_QUOTED || mod == UNQUOTED))
			*string = ENC_DQ;
		if (*string == '\'' && (mod == S_QUOTED || mod == UNQUOTED))
			*string = ENC_SQ;
		string++;
	}
	return (line);
}
