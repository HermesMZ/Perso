#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <bsd/string.h>
#include "../libft.h"

typedef struct s_test_ft_strlcpy
{
	const char	*src;
	size_t	n;
}				t_test_ft_strlcpy;


void	test_ft_strlcpy(void)
{
	t_test_ft_strlcpy	tests[] = 
	{
		{"", 0},
		{"", 1},
		{"  ", 1},
		{"abcde", 1},
		{"abcde", 5},
		{"abcde", 6},
		{"abcde", 10},
		{"\nabcde", 3},
		{"\nabcde\n", 7},
	};
	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	size_t	ok_count = 0;
    size_t	fail_count = 0;
	char	ft_result[50]; 
	char	std_result[50]; 

	memset(ft_result,0,50);
	memset(std_result,0,50);
	printf("\nft_strlcpy tests :\t\t");
	while (i < num_tests)
	{
		size_t	ft = ft_strlcpy(ft_result, tests[i].src, tests[i].n);
		size_t	std = strlcpy(std_result, tests[i].src, tests[i].n);
		if ((ft == std) && (strcmp(ft_result, std_result) == 0))
			ok_count++;
		else
		{
			fail_count++;
			printf("\n%zu KO (expected %zu\"%s\", got %zu\"%s\")\n", i + 1, std, std_result, ft, ft_result);
		}
		i++;
	}
    if (fail_count == 0)
		printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}