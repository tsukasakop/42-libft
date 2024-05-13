# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkondo <tkondo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2024/05/13 13:16:50 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and compiling flags
CC = cc
CFLAGS = -g -fsanitize=address -Wall -Wextra -Werror

# Source and object files
S_ALL =\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_strlen.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_strncmp.c\
	ft_memchr.c\
	ft_memcmp.c\
	ft_strnstr.c\
	ft_atoi.c\
	ft_calloc.c\
	ft_strdup.c\
	ft_substr.c\
	ft_strjoin.c\
	ft_strtrim.c\
	ft_split.c\
	ft_itoa.c\
	ft_strmapi.c\
	ft_striteri.c\
	ft_putchar_fd.c\
	ft_putstr_fd.c\
	ft_putendl_fd.c\
	ft_putnbr_fd.c\

S_BONUS =\
	ft_lstnew.c\
	ft_lstadd_front.c\
	ft_lstsize.c\
	ft_lstlast.c\
	ft_lstadd_back.c\
	ft_lstdelone.c\
	ft_lstclear.c\
	ft_lstiter.c\
	ft_lstmap.c\

O_ALL = $(S_ALL:%.c=%.o)
O_BONUS = $(S_BONUS:%.c=%.o)

ifdef ADD_BONUS
O_ALL += $(O_BONUS)
endif

# Name of the library
NAME = libft.a

# Default target
all: $(NAME)

# Rule for creating the library
$(NAME): $(O_ALL)
	ar rcs $(NAME) $(O_ALL)

# Rule for bonus target
bonus: $(O_BONUS)
	ar rcs $(NAME) $(O_BONUS)

# Rule for creating extra

# Rule for compiling source files
%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

# Rule for cleaning object files
clean:
	rm -f $(O_ALL) $(O_BONUS)

# Rule for full clean
fclean: clean
	rm -f $(NAME)

# Rule for re-making
re: fclean all

# Phony targets
.PHONY: all bonus clean fclean re

