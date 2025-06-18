#!/bin/bash

gcc -Wall -Wextra -Werror -c srcs/ft_putchar.c
gcc -Wall -Wextra -Werror -c srcs/ft_strlen.c
gcc -Wall -Wextra -Werror -c srcs/ft_putstr.c
gcc -Wall -Wextra -Werror -c srcs/ft_strcmp.c
gcc -Wall -Wextra -Werror -c srcs/ft_swap.c
# -c pour créer des objets de chaque fichier. Précompiler.

ar rc libft.a ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o
# ar pour archive. r pour remplacer l'ancien. c pour créer l'archive si elle n'existe pas.

ranlib libft.a
# accélère et assure la création des liens à la compilation.

rm -f *.o
# supprime les .o pour faire le ménage.

echo "libft.a created successfully."