# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-hich <hel-hich@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/26 02:58:20 by eel-moun          #+#    #+#              #
#    Updated: 2022/11/26 20:47:54 by hel-hich         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = minishell.c int_minishell.c expand.c parse.c free_tree.c\
	exe/check_built_in.c exe/check_rdr.c exe/execute.c\
		exe/execute_pipe.c exe/execute_built_in.c exe/execute_execve.c\
			exe/execute_fork_set.c exe/execute_signals.c exe/execute_simple_cmd.c\
				exe/execute_simple_cmd_pid.c\
	parse/quotes_enc.c parse/rm_quotes_enc.c parse/switch_mode_enc.c\
		parse/create_node.c parse/ft_lexer.c parse/next_token.c parse/parse_glob.c\
			parse/parse_pipline.c parse/parse_rdr.c parse/init_rdr.c\
				parse/switch_mode.c parse/parse_cmd.c\
	env/add_env.c env/free_env.c env/env.c env/int_env.c\
		env/set_env.c env/update_env.c env/find_env.c\
			env/p_env.c env/unset_env.c\
	built_in/cd.c built_in/echo.c built_in/env.c\
		built_in/exit.c built_in/export.c built_in/pwd.c\
			built_in/unset.c\

NAME = minishell

CC = cc

CFLAGS = -L /Users/$(USER)/.homebrew/opt/readline/lib -I /Users/$(USER)/.homebrew/opt/readline/include -Wall -Wextra -Werror -MMD

DEP = $(SRC:.c=.d)

$(NAME): $(SRC) libft/libft.a
	@$(CC) $(CFLAGS) -o $(NAME) $(SRC) libft/libft.a -lreadline

.PHONY: all re clean fclean bonus

libft/libft.a:
	make -C Libft all

all: $(NAME)

clean:
	rm -rf $(DEP)

fclean:
	rm -rf $(NAME) $(DEP)

re: fclean all
-include $(DEP)
