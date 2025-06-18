#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <bsd/string.h>
#include "../libft.h"

typedef struct s_test_ft_strlcat
{
	char	ft_dst[10];
	char	std_dst[10];
	const char	*src;
	size_t	n;
}				t_test_ft_strlcat;


void	test_ft_strlcat(void)
{
	t_test_ft_strlcat	tests[] = 
	{
		{"", "", "", 0},
		{"", "", "", 1},
		{"", "", "  ", 1},
		{"", "", "abcde", 1},
		{"", "", "abcde", 5},
		{"", "", "abcde", 6},
		{"", "", "abcde", 10},
		{"", "", "\nabcde", 3},
		{"", "", "\nabcde\n", 7},		
		{"12345", "12345", "", 0},
		{"12345", "12345", "", 1},
		{"12345", "12345", "  ", 1},
		{"12345", "12345", "abcde", 1},
		{"12345", "12345", "abcde", 5},
		{"12345", "12345", "abcde", 6},
		{"12345", "12345", "abcde", 10},
		{"12345", "12345", "\nabcde", 3},
		{"12345", "12345", "\nabcde\n", 7},
	};
	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	size_t	ok_count = 0;
    size_t	fail_count = 0;

	printf("\nft_strlcat tests :\t\t");
	while (i < num_tests)
	{
		size_t	ft = ft_strlcat(tests[i].ft_dst, tests[i].src, tests[i].n);
		size_t	std = strlcat(tests[i].std_dst, tests[i].src, tests[i].n);
		if ((ft == std) && (strcmp(tests[i].ft_dst, tests[i].std_dst) == 0))
			ok_count++;
		else
		{
			fail_count++;
			printf("\n%zu KO (expected %zu\"%s\", got %zu\"%s\")\n", i + 1, std, tests[i].std_dst, ft, tests[i].ft_dst);
		}
		i++;
	}
    if (fail_count == 0)
		printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}