# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2024/12/16 18:05:56 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
INC_DIR = include
CFLAGS = -Wall -Wextra -Werror -I$(INC_DIR)

SRC_DIR = src
OBJ_DIR = bin
NAME = libft.a
TARGET =\
	ft_isalpha\
	ft_isdigit\
	ft_isalnum\
	ft_isascii\
	ft_isprint\
	ft_strlen\
	ft_memset\
	ft_bzero\
	ft_memcpy\
	ft_memmove\
	ft_strlcpy\
	ft_strlcat\
	ft_toupper\
	ft_tolower\
	ft_strchr\
	ft_strrchr\
	ft_strcmp\
	ft_strncmp\
	ft_memchr\
	ft_memcmp\
	ft_strnstr\
	ft_atoi\
	ft_calloc\
	ft_strdup\
	ft_substr\
	ft_strjoin\
	ft_strtrim\
	ft_split\
	ft_itoa\
	ft_strmapi\
	ft_striteri\
	ft_putchar_fd\
	ft_putstr_fd\
	ft_putendl_fd\
	ft_putnbr_fd\
	ft_lstnew\
	ft_lstadd_front\
	ft_lstsize\
	ft_lstlast\
	ft_lstadd_back\
	ft_lstdelone\
	ft_lstclear\
	ft_lstiter\
	ft_lstmap\
	ft_fileno\
	ft_fwrite\
	ft_fputc\
	ft_fflush\
	ft_vfprintf\
	ft_printf\
	ft_htbl0\
	ft_htbl1\
	ft_memory\
	ft_global\

OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(TARGET)))

all: $(NAME)

dev: CFLAGS+=-g -fsanitize=address
dev: all

$(NAME): $(OBJS)
	ar rcs $(NAME) $?

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: dev all clean fclean re init
