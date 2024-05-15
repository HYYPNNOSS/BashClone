/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_glob.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 18:22:52 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 19:47:32 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_glob(char *str)
{
	int	mod;

	mod = UNQUOTED;
	while (*str)
	{
		if (mod == UNQUOTED && *str == '*')
			return (1);
		mod = enc_mode_switch(mod, *str);
		str++;
	}
	return (0);
}

static int	glob_match_rec(char *str, const char *d_name, int mod)
{
	const char	*d_start = d_name;

	while (1)
	{
		while (*str == ENC_SQ || *str == ENC_DQ)
			mod = enc_mode_switch(mod, *str++);
		if (*str == '\0')
			return (*d_name == '\0');
		else if (mod == UNQUOTED && *str == '*')
		{
			while (*str == ENC_SQ || *str == ENC_DQ
				|| (mod == UNQUOTED && *str == '*'))
					mod = enc_mode_switch(mod, *str++);
			if ((*d_name == '.' && d_name == d_start) || *str == '/')
				return (0);
			if (*str == '\0')
				return (1);
			while (*d_name != '\0')
				if (glob_match_rec(str, d_name++, mod))
					return (1);
			return (0);
		}
		else if (*str++ != *d_name++)
			return (0);
	}
}

static t_lst	*is_match(char *str)
{
	t_lst			*lst;
	DIR				*dirp;
	struct dirent	*dp;

	dirp = opendir(".");
	if (!dirp)
		return (NULL);
	dp = readdir(dirp);
	lst = NULL;
	while (dp)
	{
		if (glob_match_rec(str, dp->d_name, UNQUOTED)
			&& !lst_put_orderly(&lst, dp->d_name))
			break ;
		dp = readdir(dirp);
	}
	closedir(dirp);
	return (lst);
}

t_lst	*global_parse(t_tkn token)
{
	t_lst	*glob;
	char	*str;

	str = ft_substr(token.str, 0, token.len);
	if (!str)
		return (perror("minishell"), NULL);
	glob = NULL;
	errno = 0;
	if (is_glob(str))
		glob = is_match(str);
	if (!glob && (errno != 0
			|| !lst_put_orderly(&glob, enc_remove_quotes(str))))
		perror("minishell");
	free(str);
	return (glob);
}
