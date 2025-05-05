# **************************************************************************** #
#                                  VARIABLES                                  #
# **************************************************************************** #

NAME        = push_swap
BONUS       = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -Iincludes
RM          = rm -f

LIBFT       = libft/libft.a
SDL2_FLAGS  = $(shell sdl2-config --cflags --libs)

# **************************************************************************** #
#                                  FICHIERS                                   #
# **************************************************************************** #

SRC_DIR     = src
OBJ_DIR     = obj

BONUS_DIR   = bonus
BONUS_OBJ_DIR = obj_bonus

# Fichiers sources communs (sans main.c)
SRC_FILES   = parsing/parsing.c parsing/error.c \
              pile/piles.c pile/utils_pile.c \
              rota/rota.c rota/swap.c rota/push.c \
              algo/algo.c algo/push_back.c algo/small.c \
              init.c index.c utils.c

COMMON_SRC  = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
COMMON_OBJ  = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))

# Fichier main.c uniquement pour push_swap
MAIN_SRC    = $(SRC_DIR)/main.c
MAIN_OBJ    = $(OBJ_DIR)/main.o

# Fichiers spécifiques au bonus
BONUS_FILES = main.c utils.c loby.c sleep.c event.c random_element.c sdl.c
BONUS_SRC   = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))
BONUS_OBJ   = $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_FILES:.c=.o))

# **************************************************************************** #
#                                   REGLES                                     #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(LIBFT) $(COMMON_OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) $(COMMON_OBJ) $(MAIN_OBJ) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(BONUS)

$(BONUS): $(BONUS_OBJ) $(COMMON_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(COMMON_OBJ) $(LIBFT) $(SDL2_FLAGS) -o $(BONUS)

# Compilation fichiers src/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Compilation fichiers bonus/
$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Libft
$(LIBFT):
	make -C libft

# Nettoyage
clean:
	$(RM) $(COMMON_OBJ) $(MAIN_OBJ) $(BONUS_OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME) $(BONUS)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re bonus
