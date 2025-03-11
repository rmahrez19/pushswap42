# Variables
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
NAME        = pushwap
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = includes
MKDIR       = mkdir -p

# Recherche des fichiers sources automatiquement dans SRC_DIR
VPATH       = $(SRC_DIR)

# Définition des fichiers sources (sans besoin de préfixer par SRC_DIR)
SRCS        = main.c parsing.c piles.c

# Fichiers objets
OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# Compilation des fichiers .c en .o
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Création du dossier obj s'il n'existe pas
$(OBJ_DIR):
	$(MKDIR) $(OBJ_DIR)

# Compilation de la libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Nettoyage des fichiers objets
clean:
	$(RM) -r $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

# Nettoyage complet (binaire + objets)
fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_DIR) fclean

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
