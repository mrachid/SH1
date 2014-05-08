# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/27 15:01:55 by mrachid           #+#    #+#              #
#    Updated: 2014/04/27 22:16:36 by mrachid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_minishell1

CPATH =		./srcs/

HPATH =		-I ./includes/ -I ./libft/includes/

SRCS =		cd.c \
			command.c \
			path.c \
			tools.c \
			setenv.c \
			unsetenv.c \
			main.c

INCLUDES =	./libft/libft.a

OBJS =		$(SRCS:.c=.o)

CC =		clang

CFLAGS =	-Wall -Wextra -Werror

RM =		rm -rf

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C libft/
			@$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(INCLUDES)

%.o:		$(CPATH)%.c
			@$(CC) -c $< $(CFLAGS) $(HPATH)

clean:
			@make -C libft/ clean
			@$(RM) $(OBJS)

fclean:		clean
			@make -C libft/ fclean
			@$(RM) $(NAME)

re:			fclean all
