# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akhanye <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/30 10:25:20 by akhanye           #+#    #+#              #
#    Updated: 2017/08/24 14:09:28 by akhanye          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	21sh

SRC			=	main.c				\
				ft_echo.c			\
				ft_cd.c				\
				ft_env.c			\
				ft_setenv.c			\
				ft_unsetenv.c		\
				ft_run.c			\
				ft_memtrace.c		\
				ft_smartfree.c			\
				ft_duplicate.c			\
				ft_getval.c				\
				ft_arguments.c			\
				ft_keytrigger.c			\
				ft_shell.c				\
				ft_signals.c			\
				ft_screen.c				\
				ft_init.c				

FLAGS		=  -Wall -Wextra -Werror

LIBRARY 	=	-L libft -lft

TERMCAPS	=	-ltermcap
			
all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	clang -g $(TERMCAPS) $(FLAGS) $(SRC) $(LIBRARY) -o $(NAME)

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: 	fclean all
