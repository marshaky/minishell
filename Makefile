CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -O3 -I /Users/yait-oul/.brew/opt/readline/include
RM			=	rm -rf
NAME		=	minishell
LIBFT		=	libft/libft.a

COMMANDS	=	commands/builtin_export.c commands/close_prgm.c \
				commands/execute_cmd.c commands/execute_pipes.c \
				commands/handle_fds.c commands/list_env.c \
				commands/run_builtins.c commands/echo.c

UTILS		=	utils/ft_realloc.c utils/prompt.c \
				utils/free2d.c utils/replace_word.c \
				utils/replace_all_words.c utils/env_controls.c \
				utils/env_init.c

PARSING		=	parsing/cmd_tree_ops.c parsing/cmd_tree_ops1.c \
				parsing/parsing.c parsing/input_split.c \
				parsing/check_separator.c parsing/parse_args.c \
				parsing/extract_redirections.c parsing/parse_redirections.c \
				parsing/replace_variables.c parsing/parse_exec.c \
				parsing/is_builtin.c parsing/heredoc.c

CFILES		=	main.c

COMMANDS_OBJ	=	$(COMMANDS:.c=.o)
UTILS_OBJ		=	$(UTILS:.c=.o)
PARSING_OBJ		=	$(PARSING:.c=.o)
CORE_OBJ		=	$(CFILES:.c=.o)

OBJS			=	$(CORE_OBJ) $(COMMANDS_OBJ) $(UTILS_OBJ) $(PARSING_OBJ)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) \
	-lreadline -L /Users/yait-oul/.brew/opt/readline/lib

$(LIBFT):
	cd libft && $(MAKE)

clean:
	$(RM) $(OBJS)
	cd libft && $(MAKE) clean

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
