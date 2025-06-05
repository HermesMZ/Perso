#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"

typedef struct s_test_ft_strjoin
{
	const char	s1[10];
	const char	s2[10];
	const char	expected[20];
}				t_test_ft_strjoin;


void	test_ft_strjoin(void)
{
	t_test_ft_strjoin	tests[] = 
	{
		{"123", "456", "123456"},
		{"", "456", "456"},
		{"123", "", "123"},
	};
	size_t	num_tests = sizeof(tests) / sizeof(tests[0]);
	size_t	i = 0;
	size_t	ok_count = 0;
    size_t	fail_count = 0;
	char	*ft;

	printf("\nft_strjoin tests :\t\t");
	while (i < num_tests)
	{
		ft = ft_strjoin(tests[i].s1, tests[i].s2);
		if (strcmp(ft, tests[i].expected) == 0)
			ok_count++;
		else
		{
			fail_count++;
			printf("\n%zu KO (expected \"%s\", got \"%s\")\n", i + 1, tests[i].expected, ft);
		}
		free(ft);
		i++;
	}
    if (fail_count == 0)
		printf("\t\tOK");
    else
        printf("\n%ld tests passed, %ld tests failed.\n", ok_count, fail_count);
}