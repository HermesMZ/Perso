#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "../libft.h"

typedef struct s_nbrfd_test
{
	int nbr;
	const char	*expected;
}				t_nbrfd_test;


void test_ft_putnbr_fd(void)
{
    t_nbrfd_test     tests[] = 
	{
		{0, "0"},
		{-1,"-1"},
		{001,"1"},
		{+1,"1"},
		{42,"42"},
		{+42,"42"},
		{-42,"-42"},
		{100,"100"},
		{2147483647,"2147483647"},
		{-2147483648,"-2147483648"},
	};
    size_t num_tests = sizeof(tests) / sizeof(tests[0]);
    size_t bytes_read;
	size_t ok_count = 0;
    size_t fail_count = 0;
    size_t i = 0;
	int     fd;
    char    buffer[50];

	printf("\nft_putnbr_fd tests :\t\t");
	while (i < num_tests)
	{
		fd = open("test_fd.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd == -1)
		{
			printf("Cannot create file.\n");
			return ;
		}
		
		ft_putnbr_fd(tests[i].nbr, fd);
		close(fd);
	
		fd = open("test_fd.txt", O_RDONLY);
		if (fd == -1)
		{
			printf("Cannot open file.\n");
			return ;
		}
	
		bytes_read = read(fd, buffer, sizeof(buffer) - 1);
		buffer[bytes_read] = '\0';
		close(fd);
	
		if (strcmp(buffer, tests[i].expected) == 0)
			ok_count++;	
		else
		{
			fail_count++;
			printf("ft_putnbr_fd : KO (expected '%s', got '%s')\n", tests[i].expected, buffer);
		}
		i++;
	}
    if (fail_count == 0)
		printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
    unlink("test_fd.txt");
}
