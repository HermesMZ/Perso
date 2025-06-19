NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src
OBJS_DIR = objs
INCLUDES_DIR = includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = \
	push_swap_init.c \
	push_swap_index.c \
	push_swap_dlist.c \
	push_swap_p.c \
	push_swap_r.c \
	push_swap_rr.c \
	push_swap_s.c \
	push_swap_sort_utils.c \
	push_swap_sort.c \
	push_swap_hard_sort.c \
	push_swap_utils_debug.c \
	push_swap_utils.c \
	push_swap.c \

SRCS_PATHS = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(SRCS_PATHS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

INCLUDES = -I $(INCLUDES_DIR) -I $(LIBFT_DIR)/includes

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(LIBFT):
	@echo "Construction de libft.a..."
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	@echo "Nettoyage des fichiers objets..."
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Nettoyage de $(NAME) et de libft..."
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
