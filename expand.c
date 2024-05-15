/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:46:47 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 20:50:21 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse/parse.h"
#include "minishell.h"
#include "env/env.h"

#define NOT_FOUND ((char *)-1)

static char	*expand_exit(char **line)
{
	if (strncmp(*line, "$?", 2))
		return (NOT_FOUND);
	return (*line += 2, ft_itoa(g_sh.exit_s));
}

static char	*expand_env(char **line)
{
	char	*val;
	char	*string;
	int		i;

	i = 0;
	string = *line;
	if (string[i++] != '$' || (!ft_isalpha(string[i]) && (string[i] != '_')))
		return (NOT_FOUND);
	string++;
	while (ft_isalnum(string[i]) || string[i] == '_')
		i++;
	*line = string + i;
	val = ft_env_n(string, i);
	if (!val)
		return (ft_strdup(""));
	return (ft_strdup(val));
}

static char	*expand_char_add(char *string, char *exp)
{
	char	*join;

	join = NULL;
	if (exp)
		join = ft_strjoin(string, exp);
	free(string);
	free(exp);
	return (join);
}

static char	*expand_char(char *string, char c)
{
	char	str[2];
	char	*join;

	str[0] = c;
	str[1] = '\0';
	join = ft_strjoin(string, str);
	free(string);
	return (join);
}

char	*expand(char *line)
{
	int		mod;
	char	*string;
	char	*exp;

	mod = UNQUOTED;
	string = ft_strdup("");
	while (string && *line)
	{
		exp = NOT_FOUND;
		mod = enc_mode_switch(mod, *line);
		if (mod != S_QUOTED)
		{
			exp = expand_exit(&line);
			if (exp == NOT_FOUND)
				exp = expand_env(&line);
		}
		if (exp == NOT_FOUND)
			string = expand_char(string, *line++);
		else
			string = expand_char_add(string, exp);
	}
	if (!string)
		perror("minishell");
	return (string);
}
