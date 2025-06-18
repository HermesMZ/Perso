#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "../libft.h"

void test_ft_putchar_fd(void)
{
    int     fd;
    char    buffer;
    char    test_char = 'A';
    ssize_t bytes_read;

    printf("\nft_putchar_fd tests :\t\t");

    fd = open("test_fd.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
    if (fd == -1)
	{
		printf("Cannot create file.\n");
		return ;
	}
    ft_putchar_fd(test_char, fd);
    close(fd);

    fd = open("test_fd.txt", O_RDONLY);
    if (fd == -1)
	{
		printf("Cannot open file.\n");
		return ;
	}
    bytes_read = read(fd, &buffer, 1);
    close(fd);

    if (bytes_read != 1)
    {
        printf("Failed to read the file.\n");
        return ;
    }

    if (buffer == test_char)
		printf("\t\tOK");
    else
        printf("ft_putchar_fd : KO (expected '%c', got '%c')\n", test_char, buffer);

    unlink("test_fd.txt");
}
