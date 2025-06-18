#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// clear && cc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c .test_bonus.c -g3 -D BUFFER_SIZE=3000 && valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./a.out get_next_line.c get_next_line.h


int main(int argc, char **argv)
{
    int     fd;
    char    *line;
    int     i;

    if (argc < 2)
    {
        printf("Usage: %s <fichier1> [fichier2 ...]\n", argv[0]);
        return (1);
    }

    i = 1;
    while (i < argc)
    {
        printf("\n--- Traitement du fichier : %s ---\n", argv[i]);

        fd = open(argv[i], O_RDONLY);
        if (fd == -1)
        {
            perror("Erreur lors de l'ouverture du fichier");
            i++;
            continue;
        }

        line = get_next_line(fd);
        while (line != NULL)
        {
            printf("%s", line);
            free(line);
            line = get_next_line(fd);
        }

        if (line == NULL)
            printf("--- Fin du fichier ou erreur pour %s ---\n", argv[i]);

        close(fd);
        i++;
    }

    return (0);
}