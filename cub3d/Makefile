# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <student@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/24  by student                  #+#    #+#              #
#    Updated: 2025/10/24  by student               ###   ########.fr          #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES)
MLX_DIR = minilibx-linux
LIBS = -L$(MLX_DIR) -lmlx_Linux -lXext -lX11 -lm -lbsd
INCLUDES = -I$(MLX_DIR)

# Note: This project uses minilibx-linux
# The library has been built and is ready to use
SRC =	main.c \
		parser.c \
		get_next_line.c \
		map_validator.c \
		raycasting.c \
		texture_utils.c \
		utils.c \
		events.c \
		graphics.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Colors
RED=\033[0;31m
GREEN=\033[0;32m
YELLOW=\033[1;33m
NC=\033[0m # No Color

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@echo "$(GREEN)✓$(NC) $(NAME) compiled successfully!"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)
	@echo "$(YELLOW)•$(NC) Compiling $<"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)✗$(NC) Objects cleaned!"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)✗$(NC) $(NAME) deleted!"

re: fclean all

test_maps:
	@echo "Testing maps with Cub3D..."
	@echo "Available maps: $(wildcard *.cub)"

.PHONY: all clean fclean re test_maps