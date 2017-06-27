# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cnovo-ri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/15 13:14:57 by cnovo-ri          #+#    #+#              #
#    Updated: 2017/05/15 16:27:40 by cnovo-ri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=FdF

SRC=draw.c check_file.c main.c

LIB=./libft/libft.a

MLX_LIB= -L ./minilibx_macos

OBJ=$(SRC:.c=.o)

FLAGS=-Wall -Wextra -Werror

CC=cc

MLX= -lmlx -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@make -C minilibx_macos
	@$(CC) $(FLAGS) -c $(SRC) -I . -I ./libft
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME) -I./ $(MLX_LIB) $(MLX) -L ./libft -lft
	@echo "\033[1m\033[32m[ ✔ ]Compiled :\033[0m $(NAME) ࿇"

clean:
	@rm -f $(OBJ)
	@make clean -C ./libft
	@make clean -C ./minilibx_macos
	@echo "\033[1m\033[32m[ ✔ ]Deleted :\033[0m $(OBJ) ࿇"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./libft
	@echo "\033[1m\033[32m[ ✔ ]Deleted :\033[0m $(NAME) ࿇"

re: fclean all

.PHONY: all clean fclean re
