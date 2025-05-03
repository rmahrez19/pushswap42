# **************************************************************************** #
#                                  VARIABLES                                  #
# **************************************************************************** #

NAME    = push_swap
BONUS   = checker
CC      = cc
CFLAGS  = -Wall -Wextra -Werror -g -Iincludes
RM      = rm -f

# SDL2
SDL2_FLAGS = $(shell sdl2-config --cflags --libs)

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

# Bonus part
BONUS_DIR = bonus
BONUS_OBJ_DIR = obj_bonus

BONUS_FILES = main.c utils.c loby.c sleep.c event.c random_element.c
BONUS_SRC   = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))
BONUS_OBJ   = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_FILES:.c=.o))

LIBFT    = libft/libft.a

# **************************************************************************** #
#                                 RULES                                        #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(SDL2_FLAGS) -o $(BONUS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C libft

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
