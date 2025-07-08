NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS_DIR = src
OBJS_DIR = objs
INCLUDES_DIR = includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = \
	check_input.c \
	chunk.c \
	cost.c \
	cost_utils.c \
	exec_moves.c \
	hard_sort.c \
	index.c \
	init.c \
	min_max.c \
	push_swap_p.c \
	push_swap_r.c \
	push_swap_rr.c \
	push_swap_s.c \
	push_swap.c \
	simple_math.c \
	sort_utils.c \
	stack_utils.c \
	stack.c \
	utils_debug.c \

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
