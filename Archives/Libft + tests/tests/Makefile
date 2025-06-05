NAME = unit_tests
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ../
OBJS_DIR = objs
LIBFT_PATH = ..
LIBFT = $(LIBFT_PATH)/libft.a

SRCS = main_test.c\
	test_characters.c \
	test_ft_atoi.c \
	test_ft_bzero.c \
	test_ft_calloc.c \
	test_ft_itoa.c \
	test_ft_memset.c \
	test_ft_memcpy.c \
	test_ft_memchr.c \
	test_ft_memmove.c \
	test_ft_memcmp.c \
	test_ft_putchar_fd.c \
	test_ft_putendl_fd.c \
	test_ft_putnbr_fd.c \
	test_ft_putstr_fd.c \
	test_ft_split.c \
	test_ft_strdup.c \
	test_ft_striteri.c \
	test_ft_strjoin.c \
	test_ft_strchr.c \
	test_ft_strlcat.c \
	test_ft_strlcpy.c \
	test_ft_strlen.c \
	test_ft_strmapi.c \
	test_ft_strncmp.c \
	test_ft_strrchr.c \
	test_ft_strnstr.c \
	test_ft_strtrim.c \
	test_ft_substr.c \
	test_uplow.c \
	test_ft_lst.c \

OBJS = $(SRCS:.c=.o)
OBJS_PATH = $(addprefix $(OBJS_DIR)/, $(OBJS))

all: $(NAME)

$(NAME): $(OBJS_PATH) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS_PATH) -L$(LIBFT_PATH) -lft -o $(NAME) -lbsd

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

run: all
	@./$(NAME)

lib:
	@$(MAKE) -C $(LIBFT_PATH)

valgrind: all
	@valgrind --leak-check=full --track-origins=yes ./$(NAME)

clean:
	@echo "Nettoyage des objets de test"
	@rm -rf $(OBJS_DIR)

fclean: clean
	@echo "Suppression de l'exécutable de test"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run lib valgrind
