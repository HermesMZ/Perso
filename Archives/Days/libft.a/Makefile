NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
OBJS_DIR = objs
INCLUDES_DIR = includes

SRCS = $(SRCS_DIR)/ft_atoi.c \
	$(SRCS_DIR)/ft_putchar.c \
       $(SRCS_DIR)/ft_putnbr.c \
       $(SRCS_DIR)/ft_putstr.c \
       $(SRCS_DIR)/ft_sort_int_tab.c \
       $(SRCS_DIR)/ft_split.c \
       $(SRCS_DIR)/ft_strcat.c \
       $(SRCS_DIR)/ft_strcmp.c \
       $(SRCS_DIR)/ft_strdup.c \
       $(SRCS_DIR)/ft_strjoin.c \
       $(SRCS_DIR)/ft_strlen.c \
       $(SRCS_DIR)/ft_strndup.c \
       $(SRCS_DIR)/ft_swap.c

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
HEADER = $(INCLUDES_DIR)/ft.h

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER) | $(OBJS_DIR)
	@echo "Compilation : $<"
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Création de la bibliothèque : $(NAME)"
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@echo "Nettoyage des objets"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Nettoyage de la bibliothèque"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re