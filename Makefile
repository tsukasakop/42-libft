# Compiler and compiling flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source and object files
SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c  ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c  ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
OBJ = $(SRC:%.c=%.o)
S_BONUS = ft_lstnew.c ft_lstadd_fron.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
O_BONUS = $(S_BONUS:%.c=%.o)

# Name of the library
LIB = libft.a

# Default target
all: $(LIB)

bonus: $(O_BONUS) $(all)
	ar rcs $(LIB) $(O_BONUS)
# Rule for creating the library
$(LIB): $(OBJ)
	ar rcs $(LIB) $(OBJ)

# Rule for compiling source files
%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

# Rule for cleaning object files
clean:
	rm -f $(OBJ)

# Rule for full clean
fclean: clean
	rm -f $(LIB)

# Rule for re-making
re: fclean all

# Phony targets
.PHONY: all clean fclean re

