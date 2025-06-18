NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = .
OBJS_DIR = .
INCLUDES_DIR = includes

SRCS_NORMAL = \
    ft_atoi.c \
    ft_bzero.c \
    ft_calloc.c \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_itoa.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_memcpy.c \
    ft_memmove.c \
    ft_memset.c \
    ft_putchar_fd.c \
    ft_putendl_fd.c \
    ft_putnbr_fd.c \
    ft_putstr_fd.c \
    ft_split.c \
    ft_strchr.c \
    ft_strdup.c \
    ft_striteri.c \
    ft_strjoin.c \
    ft_strlcat.c \
    ft_strlcpy.c \
    ft_strlen.c \
    ft_strmapi.c \
    ft_strncmp.c \
    ft_strnstr.c \
    ft_strrchr.c \
    ft_strtrim.c \
    ft_substr.c \
    ft_tolower.c \
    ft_toupper.c

SRCS_BONUS = \
    ft_lstadd_back_bonus.c \
    ft_lstadd_front_bonus.c \
    ft_lstclear_bonus.c \
    ft_lstdelone_bonus.c \
    ft_lstiter_bonus.c \
    ft_lstlast_bonus.c \
    ft_lstmap_bonus.c \
    ft_lstnew_bonus.c \
    ft_lstsize_bonus.c

SRCS_NORMAL_PATHS = $(addprefix $(SRCS_DIR)/, $(SRCS_NORMAL))
OBJS_NORMAL = $(SRCS_NORMAL_PATHS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

SRCS_BONUS_PATHS = $(addprefix $(SRCS_DIR)/, $(SRCS_BONUS))
OBJS_BONUS = $(SRCS_BONUS_PATHS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS_NORMAL)
	ar rcs $(NAME) $(OBJS_NORMAL)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

bonus: $(NAME) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

$(OBJS_BONUS): $(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

clean:
	@echo "Nettoyage des objets"
	@rm -f $(OBJS_DIR)/*.o

fclean: clean
	@echo "Nettoyage de la bibliothèque"
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re