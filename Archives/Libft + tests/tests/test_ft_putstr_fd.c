#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../libft.h"

void test_ft_putstr_fd(void)
{
    int     fd;
    char    buffer[50];
    char *test_str = "Abcdef123";
    ssize_t bytes_read;

    printf("\nft_putstr_fd tests :\t\t");

    fd = open("test_fd.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd == -1)
    {
        printf("Cannot create file.\n");
        return ;
    }
    ft_putstr_fd(test_str, fd);
    close(fd);

    fd = open("test_fd.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Cannot open file.\n");
        return ;
    }

    bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    close(fd);

    if (bytes_read < 0)
    {
        printf("Failed to read the file.\n");
        return ;
    }

    buffer[bytes_read] = '\0';

    if (strcmp(buffer, test_str) == 0)
		printf("\t\tOK");
    else
        printf("ft_putstr_fd : KO (expected \"%s\", got \"%s\")\n", test_str, buffer);

    unlink("test_fd.txt");
}
