# **************************************************************************** #
#                                  VARIABLES                                  #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -Iincludes
RM      = rm -f

# **************************************************************************** #
#                                  SOURCES                                    #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj

SRC_FILES = main.c \
            parsing/parsing.c parsing/error.c \
            pile/piles.c pile/utils_pile.c \
            rota/rota.c rota/swap.c rota/push.c \
            algo/algo.c algo/push_back.c algo/small.c \
            init.c index.c utils.c

SRC      = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ      = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

LIBFT    = libft/libft.a

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re