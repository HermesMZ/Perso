NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS_DIR = .
OBJS_DIR = objs
INCLUDES_DIR = .

SRCS = \
    ft_atoi.c \
    ft_bzero.c \
    ft_calloc.c \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_itoa.c \
    ft_itoa_ll.c \
    ft_memchr.c \
    ft_memcmp.c \
    ft_memcpy.c \
    ft_memmove.c \
    ft_memset.c \
    ft_ptoa.c \
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
    ft_strndup.c \
    ft_strnstr.c \
    ft_strrchr.c \
    ft_strtrim.c \
    ft_substr.c \
    ft_tolower.c \
    ft_realloc.c \
    ft_toupper.c \
    ft_toupper_string.c \
    ft_utohex.c \
    ft_lstadd_back.c \
    ft_lstadd_front.c \
    ft_lstclear.c \
    ft_lstdelone.c \
    ft_lstiter.c \
    ft_lstlast.c \
    ft_lstmap.c \
    ft_lstnew.c \
    ft_lstsize.c

SRCS_PATHS = $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS = $(SRCS_PATHS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

bonus: all

clean:
	@echo "Nettoyage des objets"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Nettoyage de la bibliothèque"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus