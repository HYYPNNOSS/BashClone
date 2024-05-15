/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:43:10 by eel-moun          #+#    #+#             */
/*   Updated: 2022/11/26 17:12:36 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "../libft/libft.h"
# include <errno.h>

typedef struct s_envir
{
	char	*name;
	char	*val;
}	t_envir;

int		creat_env(char **env);

t_envir	*envr_init(char *name, char *val);

void	env_free(t_envir *env);

int		shlvl_env(void);

char	*ft_env(char *name);

char	*ft_env_n(char *name, int i);

char	**ft_env_p(void);

int		envr_set(char *name, char *val);

int		unset_env(char *name);

t_lst	*ft_found(t_lst *lst_env, char *name);

int		add_env(char *name, char *val);

int		update_env(t_envir *env, char *val);

int		comp_env(t_envir *env1, t_envir *env2);

#endif