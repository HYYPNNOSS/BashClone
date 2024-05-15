/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:47:20 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 20:49:57 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H

# define LEXER_H
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libft/libft.h"
# include "../env/env.h"

# define METACH " \t\n|&()<>"
# define UNQUOTED 1
# define S_QUOTED 2
# define D_QUOTED 3

typedef enum s_err
{
	L_EOF,
	L_EOT,
}	t_err;

typedef enum s_type
{
	ERROR = -1,
	EOF_T,
	PIPE,
	l_I,
	l_O,
	l_R_O,
	l_R_I,
	STR,
}	t_type;

typedef struct s_lexer
{
	int		pos;
	char	*line;
	t_err	error;
}	t_lxr;

typedef struct s_token
{
	char	*str;
	int		len;
	t_type	type;
}	t_tkn;

t_tkn	token_int(t_type type, char *str, int len);

t_tkn	next_token(t_lxr *lexer);

t_tkn	token_peak(t_lxr *lexer);

t_tkn	lexer_next(t_lxr *lexer);

t_lxr	lexer_int(char *line);

int		mode_switch(int mod, char c);

void	lexer_advence(t_lxr *lexer, int n);

int		enc_mode_switch(int mod, char c);

#endif