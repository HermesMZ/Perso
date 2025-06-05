NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = srcs
OBJS_DIR = objs
INCLUDES_DIR = includes

SRCS = $(SRCS_DIR)/ft_putchar.c \
       $(SRCS_DIR)/ft_swap.c \
       $(SRCS_DIR)/ft_putstr.c \
       $(SRCS_DIR)/ft_strlen.c \
       $(SRCS_DIR)/ft_strcmp.c

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)
HEADER = $(INCLUDES_DIR)/ft.h

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(HEADER) | $(OBJS_DIR)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Creating library: $(NAME)"
	@ar rcs $(NAME) $(OBJS)

all: $(NAME)

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@echo "Cleaning objects"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Cleaning library"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re