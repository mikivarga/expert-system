#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvarga <mvarga@student.unit.ua>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 13:49:28 by mvarga            #+#    #+#              #
#    Updated: 2019/03/21 14:47:51 by mvarga           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = expert_system

FLAGS = -Wall -Wextra -Werror
CC = gcc

INC_DIR = inc
SRC_DIR = src
OBJ_DIR = obj
LIB_DIR = lib

SRC = $(addprefix $(SRC_DIR)/, main.c parser.c get_next_line.c algorithm.c display.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
INC = $(addprefix $(INC_DIR)/, expert_system.h)

LIBFT_DIR = $(LIB_DIR)/ft_printf
LIBFT = $(LIBFT_DIR)/libftprintf.a
LIBFT_INC = $(LIBFT_DIR)/inc
LIBFT_FLAGS = -l$(LIBFT_DIR)

LINK_FLAGS = $(LIBFT)
HEADER_FLAGS = -I$(LIBFT_INC) -I$(INC_DIR)

RED = \033[01;31m
GREEN = \033[01;32m
YELLOW = \033[01;33m
BLUE = \033[01;34m
PINK = \033[01;35m
RESET = \033[00m

all : $(LIBFT) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FLAGS) $(LINK_FLAGS) -o $(NAME)
	@echo "$(YELLOW)make:$(RESET)\t$(NAME)"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(BLUE)create:$(RESET)\t$(OBJ_DIR)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC)
	@$(CC) $(HEADER_FLAGS) -c $< -o $@ $(FLAGS)
	@echo "$(GREEN)compil:$(RESET)\t$@"

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
	@echo "$(RED)clean:$(RESET)\t$(OBJ)"

fclean:
	@rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@make fclean -C $(LIBFT_DIR)
	@echo "$(RED)fclean:$(RESET)\t$(NAME)"

re: fclean all

.PHONY: clean fclean re