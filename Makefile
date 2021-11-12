# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#   By: eparviai <eparviai@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 16:58:46 by eparviai          #+#    #+#              #
#    Updated: 2019/10/23 16:58:48 by eparviai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Name

NAME =	fdf

# Source files
SRC_FILES = main.c draw.c reader.c
OBJ_FILES = $(SRC_FILES:.c=.o)

# Compile flags
CFLAGS = -Wall -Wextra -Werror -g

# Paths
SRC_DIR = ./srcs/
OBJ_DIR = ./objs/
INC_DIR = ./includes/
FT_DIR = ./libft/
FT_INC_DIR = ./libft/includes/

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
LIBFT = $(addprefix $(FT_DIR), libft.a)

# /usr/local/lib/libmlx.a -lm -lX11 -lXext
# Libft and Minilibx linkers
LNK  = -L $(FT_DIR)\
			-I /usr/local/include -L /usr/local/lib \
    		-l mlx -l ft -framework OpenGL -framework Appkit

# Fancy coloring codes
GREEN = \033[0;32m
RED = \033[0;31m
END = \033[0m


all: obj $(LIBFT) $(NAME)


obj:
	@mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@gcc $(CFLAGS) -I $(FT_DIR) -I $(INC_DIR) -I $(FT_INC_DIR) -o $@ -c $<

$(LIBFT):
	@make -C $(FT_DIR)

# Compiler
$(NAME): $(OBJ)
	@echo "Compiling... Wait a sec."
	@gcc $(OBJ) $(LNK) -o $(NAME)

clean:
	@rm -rdf $(OBJ_DIR)
	@make -C $(FT_DIR) clean
	@echo "$(NAME): $(RED)All object files were deleted.$(END)"

fclean: clean
	@rm -f $(NAME)
	@make -C $(FT_DIR) fclean
	@echo "$(NAME): $(RED)$(NAME) was deleted$(END)"

re:	fclean all

.PHONY: all clean fclean re
.PRECIOUS: author
