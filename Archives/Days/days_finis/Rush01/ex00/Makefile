NAME	=	rush-01

SRC		=	back_tracking.c \
			check_cell.c \
			main.c \
			parsing.c \
			rush01.c \
			tab_1.c \
			tab.c

BUILD	= .build/

OBJ		=	$(addprefix $(BUILD), $(SRC:.c=.o))

DEPS	=	$(addprefix $(BUILD), $(OBJ:.o=.d))

CC		= cc

CFLAGS	+= -Wall -Wextra -Werror -MMD -MP

all: $(NAME)

$(NAME): $(BUILD) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(BUILD):
	@mkdir $@

$(BUILD)%.o:	%.c Makefile rush01.h
	$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -fr $(BUILD)

fclean: clean
	@rm -fr $(NAME)

re: fclean all 

.PHONY: all re clean fclean 

-include $(DEPS)