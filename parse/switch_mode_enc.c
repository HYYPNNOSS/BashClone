/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enc_switch_mode.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:47:30 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 16:51:53 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	enc_mode_switch(int mod, char c)
{
	if (c == ENC_SQ)
	{
		if (mod == S_QUOTED)
			return (UNQUOTED);
		if (mod == UNQUOTED)
			return (S_QUOTED);
	}
	else if (c == ENC_DQ)
	{
		if (mod == D_QUOTED)
			return (UNQUOTED);
		if (mod == UNQUOTED)
			return (D_QUOTED);
	}
	return (mod);
}
