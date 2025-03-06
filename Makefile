# Variables
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
NAME        = pushwap
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a
SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = includes
MKDIR       = mkdir -p   # Définir la commande mkdir pour créer des répertoires

SRCS        = $(SRC_DIR)/main.c

# Fichiers objets (crée les noms des fichiers .o correspondants)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Nom de l'exécutable
NAME        = pushwap

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# Compilation des fichiers .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
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
