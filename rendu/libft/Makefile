# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bduron <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 17:43:34 by bduron            #+#    #+#              #
#*   Updated: 2016/11/14 20:58:43 by bduron           ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

OS= $(shell uname -s)

NAME= libft.a
SRC= \
ft_printf_atoi.c \
ft_printf.c \
ft_printf_conv.c \
ft_printf_digits.c \
ft_printf_getarg.c \
ft_printf_itoa.c \
ft_printf_parsing.c \
ft_printf_percent.c \
ft_printf_strings.c \
ft_printf_strings_utils.c \
ft_printf_utils.c \
ft_printf_wildcard.c \
get_next_line.c \
ft_bzero.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_lstappend.c \
ft_lstpush.c \
ft_lstpop.c \
ft_lstaddback.c \
ft_lstadd.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstlen.c \
ft_lstinttab.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strrev.c \
ft_strsplit.c \
ft_strsplitdel.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_atoi.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isdigitstr.c \
ft_islower.c \
ft_isprint.c \
ft_isspace.c \
ft_isupper.c \
ft_itoa.c \
ft_squeeze.c \
ft_tolower.c \
ft_toupper.c \
ft_graph_bfs.c \
ft_graph.c \
ft_graph_shortestpath.c \
ft_getline.c 
 
	

OBJ= $(SRC:.c=.o)
HEADER= includes
FLAGS= -g -Wall -Wextra -Werror

VPATH= 	src/ft_printf/:src/get_next_line/:src/memory/:\
		src/print/:src/single_linked_list/:src/strings/:src/utils/:\
		src/graph


########################
#    Makefile rules    # 
########################

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@ranlib $@
ifeq ($(OS),Linux)
	@tput ed
	@echo -e 'Libft linked [\033[32mDone\033[0m]'
endif
ifeq ($(OS),Darwin)
	@printf '\033[K'
	@echo 'Libft compiled'
endif	

%.o: %.c
	@gcc $(FLAGS) -c $^ -I $(HEADER)
ifeq ($(OS),Linux)
	@tput ed	
	@echo -ne 'Compiling [\033[32m$^\033[0m]\r'
endif
ifeq ($(OS),Darwin)
	@printf '\033[K'
	@printf 'Compiling [$^]\r'
endif

clean:
	@rm -f $(OBJ)
	@echo "Deleting object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Deleting libft.a"

re: fclean all

.PHONY: clean fclean re
