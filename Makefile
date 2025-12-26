NAME = minishell

CC = cc
CFLAGS = -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	READLINE_DIR := $(shell brew --prefix readline)
	READLINE_INC = -I$(READLINE_DIR)/include
	READLINE_LIB = -L$(READLINE_DIR)/lib -lreadline
else
	READLINE_INC =
	READLINE_LIB = -lreadline
endif

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a
INC = -Iinclude -I$(LIBFT_DIR) $(READLINE_INC)

SRC = \
	src/main.c \
	src/cmd.c \
	src/cmd2.c \
	src/env.c \
	src/parser.c \
	src/tokens.c \
	src/unset.c \
	src/utils.c \
	src/validation_token.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(READLINE_LIB) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
