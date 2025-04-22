# **************************************************************************** #
#                                  VARIABLES                                   #
# **************************************************************************** #

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
NAME        = push_swap

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = includes
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

# Commande pour créer un dossier
MKDIR       = mkdir -p

# Recherche les fichiers sources automatiquement dans SRC_DIR
VPATH       = $(SRC_DIR)

# Liste des fichiers sources (chemins relatifs à SRC_DIR)
SRCS        = main.c parsing.c piles.c error.c rota/rota.c  rota/swap.c rota/push.c small.c utils.c algo.c utils_pile.c init.c index.c

# Création des objets dans obj/ en gardant la structure des sous-dossiers
OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

# Règle par défaut
all: $(NAME)

# Compilation de l'exécutable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

# Compilation des fichiers .c en .o, avec création auto des sous-dossiers dans obj/
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

# Compilation de la libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Nettoyage des fichiers objets
clean:
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean

# Nettoyage complet (binaire + objets)
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Recompilation complète
re: fclean all

.PHONY: all clean fclean re
