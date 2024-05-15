/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 01:46:58 by hel-hich          #+#    #+#             */
/*   Updated: 2022/11/26 19:47:32 by hel-hich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H

# define PARSE_H
# include "../libft/libft.h"
# include <string.h>
# include <errno.h>
# include <stdbool.h>
# include <dirent.h>
# include "lexer.h"

# define ENC_DQ	-1
# define ENC_SQ -2

# define RULE_E ((void *)-1)

///////////////////////////// RDR

typedef enum e_rdr_type
{
	R_I = 1,
	R_O,
	I,
	O,
}	t_rdr_type;

typedef struct s_rdr
{
	char		*rdr;
	t_rdr_type	type;
}	t_rdr;

///////////////////////////// CMD

typedef enum e_parse_type
{
	simple_cmd,
	Pipe,
}	t_parse_type;

typedef struct s_parse
{
	t_lst			*rdr_lst;
	t_parse_type	type;
	int				ac;
	char			**av;
	struct s_parse	*left;
	struct s_parse	*right;
}	t_prs;

t_prs	*parse(char *line);

t_prs	*parse_line(t_lxr *lexer);

t_prs	*parse_pipline(t_lxr *lexer);

t_prs	*command_pasre(t_lxr *lexer);

t_prs	*pipe_parse(t_lxr *lexer);

t_prs	*create_node(t_lst **rdr_lst, t_lst **arg_lst);

t_prs	*init_parse(t_parse_type type, t_prs *left, t_prs *right);

t_lst	*command_pasre_elem(t_lxr *lexer, t_lst **rdr_lst, t_lst **arg_lst);

t_lst	*global_parse(t_tkn token);

t_lst	*redirection_parse(t_lxr *lexer, t_lst **rdr_lst);

t_lst	*redirection_add(t_rdr_type rdr_type, t_tkn str, t_lst **arg_lst);

t_rdr	*redirection_init(t_rdr_type rdr_type, t_tkn str);

///////////////////////////UTTILES

int		mode_switch(int mod, char c);

char	*expand(char *line);

char	*enc_quotes(char *line);

char	*enc_remove_quotes(char *str);

char	**frm_lst_to_str(t_lst *arg_lst);

void	print_err(t_lxr *lexer, t_tkn token);

void	str_free(char **str);

void	free_tree_node(t_prs *parse);

void	free_rdr(t_rdr *rdr);

void	free_tree(t_prs **parse);

void	handler(int sig);

int		event(void);

#endif