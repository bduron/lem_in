# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bduron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/07 13:02:54 by bduron            #+#    #+#              #
#    Updated: 2017/03/07 18:04:39 by bduron           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM_IN= lem-in

CC= gcc
CFLAGS= -Wall -Wextra -Werror -g #-fsanitize=address
LIBFT= -Llibft -lft 

MKDIR= mkdir -p
RM= rm -rf

INC_DIR= includes/

SRC= \
ft_graph.c \
ft_graph_bfs.c \
ft_graph_shortestpath.c \
lemin.c \
lemin_init.c \
lemin_parsing.c \
lemin_parsing_wrapper.c \
lemin_parsing_helper.c \
lemin_parsing_helper2.c \
lemin_move_ants.c \
lemin_get_path.c \
lemin_free.c \
addtolibft.c


OBJ= $(SRC:.c=.o)

VPATH= srcs/

########################
#    Makefile rules    # 
########################

all: libft $(LEM_IN)

libft:
	@make -C libft

# Executables 

$(LEM_IN): $(OBJ)
	@$(CC) -o $@ $(CFLAGS) $^ -I $(INC_DIR) $(LIBFT) 
	@echo "Compiling [$@]"

# Object files 

$(OBJ): $(SRC)
	@$(CC) -c $^ $(CFLAGS) -I $(INC_DIR) 
	@echo "Compiling [$^]"

# Cleaning rules 

clean:
	@rm -f $(OBJ)
	@echo "Cleaning [$(OBJ)]"	

fclean: clean
	@rm -rf $(LEM_IN)
	@make fclean -C libft
	@echo "Cleaning [libft lem_in]"	

re: fclean all

.PHONY: clean fclean re libft 
