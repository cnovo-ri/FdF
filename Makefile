# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 13:14:57 by cnovo-ri          #+#    #+#              #
#    Updated: 2017/11/01 03:43:22 by cnovo-ri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS = main.c check_file.c draw.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

HEADER = -I./

FLAG_MLX = -L/usr/local/lib/ -I/usr/local/include -lm -lmlx -framework OpenGL -framework AppKit

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	@make re -C ./libft/
	@echo "\033[1m\033[32m[ ✔ ]Compilation succes :\033[0m libft"
	@gcc -o $(NAME) $(SRCS) $(HEADER) $(FLAG_MLX) $(LIBFT)
	@echo "\033[1m\033[32m[ ✔ ]Compilation succes :\033[0m $(NAME)"

clean :
	@rm -f $(OBJS)
	@echo "\033[1m\033[31m[ ✔ ]Deleting succes :\033[0m $(OBJS)"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[1m\033[31m[ ✔ ]Deleting succes :\033[0m $(NAME)"

re : fclean all

.PHONY: all clean fclean re
